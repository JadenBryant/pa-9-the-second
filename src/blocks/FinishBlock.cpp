//
// Created by jdnkw on 12/5/2024.
//

#include "FinishBlock.h"

#include "../Player.h"

FinishBlock::FinishBlock(sf::Vector2f position) : Block(position) {
    isCollidable = true;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "FinishBlock";
}

FinishBlock::FinishBlock(int x, int y) : Block(x, y) {
    isCollidable = true;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "FinishBlock";
}

void FinishBlock::onTouch(bool& isGameOver, Player& whoTouched) {
    whoTouched.setWalkSpeed(0);
    isGameOver = true;
}
