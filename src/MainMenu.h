//
// Created by Tim on 12/3/2024.
//

#ifndef MAINMENU_H
#define MAINMENU_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class MainMenu {
private:
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<sf::Text> menuItems;
    int selectedItemIndex;

    void initMenu();
    void centerText(sf::Text& text, float yPosition);

public:
    MainMenu(sf::RenderWindow& window);
    void draw();
    void moveUp();
    void moveDown();
    int getSelectedItem() const { return selectedItemIndex; }
    void handleInput(const sf::Event& event);
    bool isMouseOverItem(const sf::Text& text) const;
};


#endif //MAINMENU_H
