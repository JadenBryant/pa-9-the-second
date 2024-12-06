//
// Created by Tim Xu on 12/6/24.
//

#include <iostream>
#include "CreditsScreen.h"

CreditsScreen::CreditsScreen(sf::RenderWindow& window) : window(window), backToMenu(false) {
    font.loadFromFile("resources/Grandstander-Regular.ttf");
    initCredits();
}

void CreditsScreen::initCredits() {
    const std::vector<std::string> items = {"Graphics: Jaden Bryant", "Physics: Daniel Bereza", "Level Design: Jackson Lusk", "Menus: Tim Xu"};
    float yOffSet = 350.0f;
    float spacing = 50.0f;

    for (int i = 0; i < items.size(); i++) {
        text.setFont(font);
        text.setString(items[i]);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);

        centerText(text, yOffSet + i * spacing);
        credits.push_back(text);
    }

    title.setFont(font);
    title.setString("Credits");
    title.setCharacterSize(80);
    title.setFillColor(sf::Color::White);
    centerText(title, 250);

    button.setFont(font);
    button.setString("Back to Main Menu");
    button.setCharacterSize(30);
    button.setFillColor(sf::Color::Yellow);
    centerText(button, 600);
}

void CreditsScreen::centerText(sf::Text& text, float yPosition) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, yPosition);
}

void CreditsScreen::draw() {
    window.clear();
    window.draw(title);
    for (int i = 0; i < credits.size(); i++) {
        window.draw(credits[i]);
    }
    window.draw(button);
    window.display();
}

void CreditsScreen::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);
        if (button.getGlobalBounds().contains(worldPos)) {
            backToMenu = true;
        }
    }
}

bool CreditsScreen::returnToMenu() const {
    return backToMenu;
}
