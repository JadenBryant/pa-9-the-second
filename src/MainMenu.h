//
// Created by Tim on 12/3/2024.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void draw();
    void handleInput(const sf::Event& event);
    bool startGame() const;

private:
    void initMenu();
    void centerText(sf::Text& text, float yPosition);
    bool isMouseOverItem(const sf::Text& text) const;

    sf::RenderWindow& window;
    sf::Font titleFont;
    sf::Font font1;
    sf::Font font2;
    std::vector<sf::Text> menuItems;
    int selectedItemIndex;
    bool gameStart;
};

#endif // MAINMENU_H