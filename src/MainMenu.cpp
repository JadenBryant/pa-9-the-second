//
// Created by Tim on 12/3/2024.
//

#include "MainMenu.h"
#include <iostream>
#include "CreditsScreen.h"

MainMenu::MainMenu(sf::RenderWindow& window) : window(window), selectedItemIndex(0), gameStart(false), credits(false) {
    titleFont.loadFromFile("resources/Gluten-Bold.ttf");
    font1.loadFromFile("resources/Grandstander-Regular.ttf");
    font2.loadFromFile("resources/WorkSans-Regular.ttf");
    backgroundTexture.loadFromFile("resources/Sky-with-Clouds.jpeg");
    initMenu();
    initMenu();
}

void MainMenu::initMenu() {
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(0.95, 0.95);
    backgroundSprite.setPosition(0, -150);

    const std::vector<std::string> items = {"Play", "Credits", "Exit"};
    float yOffSet = 400.0f;
    float spacing = 75.0f;

    for (int i = 0; i < items.size(); i++) {
        sf::Text text;
        text.setFont(font1);
        text.setString(items[i]);
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);

        centerText(text, yOffSet + i * spacing);
        menuItems.push_back(text);
    }

    sf::Text title;
    title.setFont(font1);
    title.setString("Platformer Game");
    title.setCharacterSize(120);
    title.setFillColor(sf::Color::White);
    centerText(title, 270.0f);
    menuItems.insert(menuItems.begin(), title);

    sf::Text instructions;
    instructions.setFont(font2);
    instructions.setString("Use arrow keys to move, reach the flag to win!");
    instructions.setCharacterSize(25);
    instructions.setFillColor(sf::Color::White);
    centerText(instructions, 725.0f);
    menuItems.push_back(instructions);
}

void MainMenu::centerText(sf::Text& text, float yPosition) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, yPosition);
}

bool MainMenu::isMouseOverItem(const sf::Text& text) const {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);
    return text.getGlobalBounds().contains(worldPos);
}

void MainMenu::draw() {
    window.draw(backgroundSprite);
    for (int i = 0; i < menuItems.size(); i++) {
        if (i > 0) {
            if (isMouseOverItem(menuItems[i])) {
                menuItems[i].setFillColor(sf::Color::Yellow);
            } else {
                menuItems[i].setFillColor(sf::Color::White);
            }
        }
        window.draw(menuItems[i]);
    }
    window.display();
}

void MainMenu::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                if (selectedItemIndex > 0) {
                    selectedItemIndex--;
                }
            break;
            case sf::Keyboard::Down:
                if (selectedItemIndex + 1 < menuItems.size() - 2) {
                    selectedItemIndex++;
                }
            break;
            case sf::Keyboard::Return:
                switch (selectedItemIndex) {
                    case 0:
                        gameStart = true;
                    break;
                    case 1:
                        credits = true;
                    break;
                    case 2:
                        window.close();
                    break;
                }
            break;
            default:
                break;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 1; i < menuItems.size(); i++) {
                if (isMouseOverItem(menuItems[i])) {
                    selectedItemIndex = i - 2;

                    sf::Event enterEvent;
                    enterEvent.type = sf::Event::KeyPressed;
                    enterEvent.key.code = sf::Keyboard::Return;
                    handleInput(enterEvent);
                }
            }
        }
    }
}

bool MainMenu::startGame() const {
    return gameStart;
}

bool MainMenu::showCredits() const {
    return credits;
}



/*
int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);
    MainMenu menu(window);

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            menu.handleInput(event);
        }

        window.clear();
        menu.draw();
        window.display();
    }
}
*/
