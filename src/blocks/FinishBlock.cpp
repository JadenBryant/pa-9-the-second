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
}

FinishBlock::FinishBlock(int x, int y) : Block(x, y) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "FinishBlock";
}

void FinishBlock::onTouch(Player& whoTouched) {
    std::cout << "Finish block was touched" << std::endl;
    whoTouched.setWalkSpeed(0);
    //isGameOver = true;
}
