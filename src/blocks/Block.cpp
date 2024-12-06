//
// Created by jaden on 12/2/2024.
//

#include "Block.h"
#include <random>

std::random_device rd;                               // Seed
std::mt19937 gen(rd());                              // Mersenne Twister generator
std::uniform_int_distribution<> dis(0, 255);         // Range for RGB values


Block::Block(sf::Vector2f position) {
    this->setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(dis(gen), dis(gen), dis(gen)));
    this->setPosition(position);

    this->Type = "Block";
};

Block::Block(int x, int y) {
    setSize(sf::Vector2f(50.f, 50.f));
    this->setFillColor(sf::Color(dis(gen), dis(gen), dis(gen)));
    setPosition(x, y);

    this->Type = "Block";
}