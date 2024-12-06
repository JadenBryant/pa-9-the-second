//
// Created by jaden on 12/2/2024.
//

#include "Block.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 255);

Block::Block(sf::Vector2f position) {
    this->setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(dis(gen), dis(gen), dis(gen)));
    this->setPosition(position);
};

Block::Block(int x, int y) {
    this->setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(dis(gen), dis(gen), dis(gen)));
    this->setPosition(x, y);
}