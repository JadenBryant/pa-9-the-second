//
// Created by jaden on 12/2/2024.
//

#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Block : public sf::RectangleShape {
public:
    Block();
    //virtual void onTouch(Player& whoTouched);
private:
    sf::Sprite blockGraphic;
    sf::Vector2f position;
    bool isCollidable;
};