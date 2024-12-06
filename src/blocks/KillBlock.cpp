//
// Created by jdnkw on 12/6/2024.
//

#include "KillBlock.h"
#include "../Player.h"

KillBlock::KillBlock(sf::Vector2f position) : Block(position) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "KillBlock";
}

KillBlock::KillBlock(int x, int y) : Block(x, y) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "KillBlock";
}

void KillBlock::onTouch(Player& whoTouched) {
    whoTouched.setPosition(0, 750);
}
