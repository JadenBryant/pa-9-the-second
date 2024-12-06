//
// Created by Tim Xu on 12/5/24.
//

#include "Game.h"

Game::Game(sf::RenderWindow &window)
    : window(window),
      isGameOver(false),
      timeToComplete(60),
      timeRemaining(999),
      gameMap(window.getSize()),
      blocks(&gameMap.blocks),
      player(blocks),
      playerCamera(player.Camera) {
    window.setFramerateLimit(144);
    playerCamera.setSize(sf::Vector2f(window.getSize()));
    // Load font
    font.loadFromFile("resources/WorkSans-Regular.ttf");

    // Initialize GUI elements
    clockGui.setFont(font);

    gameOverModal.setOutlineThickness(3);
    gameOverModal.setOutlineColor(sf::Color::Black);
    gameOverModal.setSize(sf::Vector2f(window.getSize().x / 4, window.getSize().y / 4));
    gameOverModal.setOrigin(gameOverModal.getSize().x / 2, gameOverModal.getSize().y / 2);
    gameOverModal.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    gameOverText.setFont(font);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setString("Game over!");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2);
    gameOverText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    for (auto event = sf::Event(); window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    // ATTRIBUTES
    int timeRunningInSeconds = static_cast<int>(gameClock.getElapsedTime().asSeconds());
    if (timeRemaining > 0 && isGameOver == false) {
        timeRemaining = timeToComplete - timeRunningInSeconds;
    } else {
        isGameOver = true;
    }

    // PLAYER MOVEMENT
    sf::Time elapsed = clock.restart();
    player.updatePhysics(elapsed);

    // PLAYER CAMERA
    playerCamera.setCenter(sf::Vector2f(player.getPosition().x, player.getPosition().y));
}

void Game::render() {
    window.clear(sf::Color(105, 203, 224));

    // DRAW WORLD
    window.setView(playerCamera);
    for (const auto block : *blocks) {
        window.draw(*block);
        if ((*block).Type == "FinishBlock") {
            auto finishBlock = dynamic_cast<FinishBlock*>(block);
            if (finishBlock) {
                finishBlock->isGameOver = &isGameOver;
            }
        }
    }
    window.draw(player);

    // GUI CODE
    auto bounds = clockGui.getLocalBounds();
    clockGui.setOrigin(bounds.width / 2, bounds.top);
    clockGui.setPosition(window.getSize().x / 2, 5);
    clockGui.setString("Time Remaining: " + std::to_string(timeRemaining));

    // DRAW GUI
    window.setView(window.getDefaultView());
    window.draw(clockGui);

    if (isGameOver) {
        window.draw(gameOverModal);
        window.draw(gameOverText);
        player.setWalkSpeed(0);
    }

    window.display();
}