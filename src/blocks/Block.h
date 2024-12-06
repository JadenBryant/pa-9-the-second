#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
// #include "../Player.h"

class Player;

class Block : public sf::RectangleShape {
public:
    explicit Block(sf::Vector2f position);
    Block(int x, int y);
    virtual void onTouch(Player& whoTouched) {}
    bool isCollidable;
};
