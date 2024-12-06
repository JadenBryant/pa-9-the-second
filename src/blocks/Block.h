//
// Created by jaden on 12/2/2024.
//

#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Block : public sf::RectangleShape {
public:
    explicit Block(sf::Vector2f position);
    Block(int x, int y);
    // virtual void onTouch(Player& whoTouched);
};