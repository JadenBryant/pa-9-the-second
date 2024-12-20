#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "blocks/Block.h"
#include "blocks/FinishBlock.h"

class Game {
public:
    Game(sf::RenderWindow &window);
    void run();
    void update();
    void draw();
    void returnToMainMenu();

private:
    void processEvents();
    void render();

    sf::RenderWindow &window;
    sf::Texture backgroundTexture;
    std::vector<sf::Sprite> backgroundSprites;
    bool isGameOver;
    int timeToComplete;
    int timeRemaining;
    sf::Clock gameClock;
    sf::Clock clock;
    Map gameMap;
    std::vector<Block*> *blocks;
    Player player;
    sf::View playerCamera;
    sf::Font font;
    sf::Text clockGui;
    sf::RectangleShape gameOverModal;
    sf::Text returnToMenuText;
    sf::Text gameOverText;
};

#endif // GAME_H