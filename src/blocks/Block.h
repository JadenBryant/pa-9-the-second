//
// Created by jaden on 12/2/2024.
//

#pragma once
#include "SFML/Graphics/RectangleShape.hpp"

class Block : sf::RectangleShape {
    Block();
    virtual ~Block();

    virtual void onContact() = 0;
};
