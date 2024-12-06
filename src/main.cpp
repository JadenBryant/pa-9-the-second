#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "blocks/Block.h"

void loadMap(std::vector<Block>& map, std::ifstream& mapFile, const sf::Vector2u& windowSize);

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "Racing Game");
    window.setFramerateLimit(144);

    // ATTRIBUTES
    bool gameOver = false;
    int timeToComplete = 10;
    int timeRemaining = 999;
    sf::Clock gameClock;
    sf::Clock clock;

    // OBJECTS
    std::vector<Block> blocks;
    Player player(&blocks);
    sf::View playerCamera = player.Camera;
    playerCamera.setSize(sf::Vector2f(window.getSize()));

    std::ifstream inputFile("../../src/resources/mapData_2.txt");
    if (inputFile.is_open()) {
        loadMap(blocks, inputFile, window.getSize());
    }
    inputFile.close();

    // GUIS
    sf::Font font;
    font.loadFromFile("resources/WorkSans-Regular.ttf");

    sf::Text clockGui;
    clockGui.setFont(font);

    sf::RectangleShape gameOverModal;
    sf::Text gameOverText;

    gameOverModal.setOutlineThickness(3);
    gameOverModal.setOutlineColor(sf::Color::Black);
    gameOverModal.setSize(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3));
    gameOverModal.setOrigin(gameOverModal.getSize().x / 2, gameOverModal.getSize().y / 2);
    gameOverModal.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    gameOverText.setFont(font);
    gameOverText.setColor(sf::Color::Black);
    gameOverText.setString("Game over!");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2);
    gameOverText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    // GAME WINDOW
    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(105, 203, 224));

        // ATTRIBUTES
        int timeRunningInSeconds = static_cast<int>(gameClock.getElapsedTime().asSeconds());
        if (timeRemaining > 0) {
            timeRemaining = timeToComplete - timeRunningInSeconds;
        } else {
            gameOver = true;
        }

        // GUI CODE
        auto bounds = clockGui.getLocalBounds();
        clockGui.setOrigin(bounds.width / 2, bounds.top);
        clockGui.setPosition(window.getSize().x / 2, 5);
        clockGui.setString("Time Remaining: " + std::to_string(timeRemaining));

        // PLAYER MOVEMENT
        sf::Time elapsed = clock.restart();
        player.updatePhysics(elapsed);

        // PLAYER CAMERA
        window.setView(playerCamera);
        playerCamera.setCenter(sf::Vector2f(player.getPosition().x, player.getPosition().y));

        // DRAW WORLD
        for (const auto& block : blocks) {
            window.draw(block);
        }
        window.draw(player);

        // DRAW GUI
        window.setView(window.getDefaultView());
        window.draw(clockGui);
        if (gameOver) {
            window.draw(gameOverModal);
            window.draw(gameOverText);
        }

        window.display();
    }
}

void loadMap(std::vector<Block>& map, std::ifstream& mapFile, const sf::Vector2u& windowSize) {
    std::string line;
    std::getline(mapFile, line); // discard header

    while (mapFile.good()) {
        std::stringstream ss;
        std::string blockType, x, y;

        std::getline(mapFile, line);
        ss.str(line);

        std::getline(ss, blockType, ',');
        std::getline(ss, x, ',');
        std::getline(ss, y);

        if (blockType == "basicBlock") {
            map.emplace_back(std::stoi(x) * 50, (windowSize.y - 50) - (std::stoi(y) * 50));
            // std::cout << "Block at position " << x << "," << y << " pushed to map vector" << std::endl;
        }
    }
}
