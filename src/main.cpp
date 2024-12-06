#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Game.h"
#include "CreditsScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    window.setFramerateLimit(144);

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
    return 0;
}