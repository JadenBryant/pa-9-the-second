//
// Created by Tim Xu on 12/5/24.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "blocks/Block.h"
#include "blocks/FinishBlock.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    bool isGameOver;
    int timeToComplete;
    int timeRemaining;
    sf::Clock gameClock;
    sf::Clock clock;
    Map gameMap;
    std::vector<Block> blocks;
    Player player;
    sf::View playerCamera;
    sf::Font font;
    sf::Text clockGui;
    sf::RectangleShape gameOverModal;
    sf::Text gameOverText;
};

#endif // GAME_H
