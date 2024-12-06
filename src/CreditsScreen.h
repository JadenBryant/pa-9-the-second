//
// Created by Tim Xu on 12/6/24.
//

#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>

class CreditsScreen {
public:
    CreditsScreen(sf::RenderWindow& window);
    void draw();
    void handleInput(const sf::Event& event);
    bool returnToMenu() const;

private:
    void initCredits();
    void centerText(sf::Text& text, float yPosition);

    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    sf::Text text;
    sf::Text button;
    std::vector<sf::Text> credits;
    bool backToMenu;
};

#endif // CREDITSSCREEN_H