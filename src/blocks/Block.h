//
// Created by jdnkw on 12/3/2024.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "../Player.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"


class Block : public sf::RectangleShape {
public:
    Block();
    ~Block();
    virtual void onTouch(Player& whoTouched) = 0;
private:
    sf::Sprite blockGraphic;
    sf::Vector2f position;
    bool isCollidable;
};



#endif //BLOCK_H
