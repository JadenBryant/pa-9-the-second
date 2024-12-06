//
// Created by jdnkw on 12/5/2024.
//

#include "FinishBlock.h"

#include <iostream>

#include "../Player.h"

FinishBlock::FinishBlock(sf::Vector2f position) : Block(position) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "FinishBlock";
    this->isGameOver = nullptr;
}

FinishBlock::FinishBlock(int x, int y) : Block(x, y) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "FinishBlock";
    this->isGameOver = nullptr;
}

void FinishBlock::onTouch(Player& whoTouched) {
    whoTouched.setWalkSpeed(0);
    *this->isGameOver = true;
}
