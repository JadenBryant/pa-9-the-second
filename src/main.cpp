#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "blocks/Block.h"

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "Racing Game");
    window.setFramerateLimit(144);

    sf::Clock clock;
    std::vector<Block> blocks;
    Player player(&blocks);
    Block block;
    block.setPosition(200, 600);
    blocks.emplace_back(block);

    sf::View playerCamera;
    playerCamera.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    playerCamera.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

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
        window.draw(block);

        sf::Time elapsed = clock.restart();
        player.updatePhysics(elapsed);
        playerCamera.setCenter(player.getPosition());
        window.draw(player);

        window.display();
    }
}
