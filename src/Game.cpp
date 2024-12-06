//
// Created by Tim Xu on 12/5/24.
//

#include "Game.h"
#include "MainMenu.h"
#include "CreditsScreen.h"
#include "blocks/KillBlock.h"

Game::Game(sf::RenderWindow &window)
    : window(window),
      isGameOver(false),
      timeToComplete(60),
      timeRemaining(999),
      gameMap(window.getSize()),
      blocks(&gameMap.blocks),
      player(blocks),
      playerCamera(player.Camera) {

    backgroundTexture.loadFromFile("resources/ScrollingBackground.jpg");

    int numBackgrounds = 6;
    sf::Vector2u textureSize = backgroundTexture.getSize();
    for (int i = 0; i < numBackgrounds; i++) {
        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setScale(0.8, 0.8);
        backgroundSprite.setPosition(i * (textureSize.x * 0.8) - 300, 0);
        backgroundSprites.push_back(backgroundSprite);
    }

    window.setFramerateLimit(144);
    playerCamera.setSize(sf::Vector2f(window.getSize()));
    // Load font
    font.loadFromFile("resources/Grandstander-Regular.ttf");

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
    gameOverText.setPosition(sf::Vector2f(window.getSize().x / 2, (window.getSize().y / 2) - 65));

    returnToMenuText.setFont(font);
    returnToMenuText.setFillColor(sf::Color::Black);
    returnToMenuText.setString("Return to Main Menu");
    returnToMenuText.setOrigin(returnToMenuText.getLocalBounds().width / 2, returnToMenuText.getLocalBounds().height / 2);
    returnToMenuText.setPosition(sf::Vector2f(window.getSize().x / 2, (window.getSize().y / 2) + 25));
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
        if (isGameOver) {
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f pos = window.mapPixelToCoords(mousePos);
                if (returnToMenuText.getGlobalBounds().contains(pos)) {
                    returnToMenuText.setFillColor(sf::Color::Yellow);
                } else {
                    returnToMenuText.setFillColor(sf::Color::Black);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);
                if (returnToMenuText.getGlobalBounds().contains(worldPos)) {
                    returnToMainMenu();
                }
            }
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

    // BACKGROUND SCROLLING
    float scrollFactor = 0.0001f;
    for (auto& backgroundSprite : backgroundSprites) {
        backgroundSprite.setPosition(-player.getPosition().x * scrollFactor + backgroundSprite.getPosition().x, 0);
    }

    // FAL OF THE NAP
    if (player.getPosition().y > 1500) {
        isGameOver = true;
    }
}

void Game::render() {
    window.clear(sf::Color(105, 203, 224));

    // DRAW WORLD
    window.setView(playerCamera);
    for (const auto& backgroundSprite : backgroundSprites) {
        window.draw(backgroundSprite);
    }
    for (const auto block : *blocks) {
        window.draw(*block);
        if ((*block).Type == "FinishBlock") {
            auto finishBlock = dynamic_cast<FinishBlock*>(block);
            if (finishBlock) {
                finishBlock->isGameOver = &isGameOver;
            }
        }
        if ((*block).Type == "KillBlock") {
            auto killBlock = dynamic_cast<KillBlock*>(block);
            if (killBlock) {
                killBlock->isGameOver = &isGameOver;
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
        window.draw(returnToMenuText);
        player.setWalkSpeed(0);
    }

    window.display();
}

void Game::returnToMainMenu() {

    MainMenu* menu = new MainMenu(window);
    CreditsScreen credits(window);

    bool showMainMenu = true;

    while (window.isOpen()) {
        for (sf::Event event; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (menu->showCredits()) {
                credits.handleInput(event);
                if (credits.returnToMenu()) {
                    delete menu;
                    menu = new MainMenu(window);
                }
            } else {
                menu->handleInput(event);
            }
        }

        if (showMainMenu) {
            window.clear();
            if (menu->showCredits()) {
                credits.draw();
            } else {
                menu->draw();
            }

            if (menu->startGame()) {
                showMainMenu = false;
            }

        } else {
            Game game(window);
            game.run();
            window.close();
        }
    }
    delete menu;
    window.close();
}