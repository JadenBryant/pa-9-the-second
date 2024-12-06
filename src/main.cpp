#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    window.setFramerateLimit(144);

    MainMenu menu(window);
    bool showMainMenu = true;

    while (window.isOpen()) {
        if (showMainMenu) {
            for (sf::Event event; window.pollEvent(event);) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                menu.handleInput(event);
            }

            window.clear();
            menu.draw();
            window.display();

            if (menu.startGame()) {
                showMainMenu = false;
            }
        } else {
            Game game;
            game.run();
            window.close();
        }
    }

    return 0;
}