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

    sf::Clock clock;
    std::vector<Block> blocks;
    Player player(&blocks);

    std::ifstream inputFile("../../src/resources/mapData_2.txt");
    if (inputFile.is_open()) {
        loadMap(blocks, inputFile, window.getSize());
    }
    inputFile.close();

    sf::View playerCamera = player.Camera;
    playerCamera.setSize(sf::Vector2f(window.getSize()));

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);

        for (const auto& block : blocks) {
            window.draw(block);
        }

        sf::Time elapsed = clock.restart();
        player.updatePhysics(elapsed);

        window.setView(playerCamera);
        playerCamera.setCenter(sf::Vector2f(player.getPosition().x, player.getPosition().y));

        window.draw(player);

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
            // all blocks placed on the bottom for now (will change)
            map.emplace_back(std::stoi(x) * 50, (windowSize.y - 50) - (std::stoi(y) * 50));
            std::cout << "Block at position " << x << "," << y << " pushed to map vector" << std::endl;
        }
    }
}
