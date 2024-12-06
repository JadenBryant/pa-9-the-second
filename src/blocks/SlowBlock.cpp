//
// Created by jdnkw on 12/6/2024.
//

#include "SlowBlock.h"
#include "../Player.h"

SlowBlock::SlowBlock(sf::Vector2f position) : Block(position) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "SlowBlock";
    this->Activated = false;
}

SlowBlock::SlowBlock(int x, int y) : Block(x, y) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "SlowBlock";
    this->Activated = false;
}

void SlowBlock::onTouch(Player& whoTouched) {
    if (this->Activated == false) {
        whoTouched.setWalkSpeed(whoTouched.getWalkSpeed() - 2);
        this->Activated = true;
    }
}
