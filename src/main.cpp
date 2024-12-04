#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::Clock clock;
    Player player;
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

        sf::RectangleShape shape(sf::Vector2f(120.f, 50.f));
        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setPosition(600, 600);
        window.draw(shape);

        sf::Time elapsed = clock.restart();
        player.updatePhysics(elapsed);
        window.draw(player);

        window.display();
    }
}
