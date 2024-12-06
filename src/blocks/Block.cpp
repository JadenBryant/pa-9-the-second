//
// Created by jaden on 12/2/2024.
//

#include "Block.h"
#include <random>

Block::Block(sf::Vector2f position) {
    this->setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(240, 240, 240));
    this->setPosition(position);

    this->Type = "Block";
};

Block::Block(int x, int y) {
    setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(240, 240, 240));
    setPosition(x, y);

    this->Type = "Block";
}