//
// Created by jdnkw on 12/6/2024.
//

#include "SpeedBoostBlock.h"
#include "../Player.h"

SpeedBoostBlock::SpeedBoostBlock(sf::Vector2f position) : Block(position) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "SpeedBoostBlock";
    this->Activated = false;
}

SpeedBoostBlock::SpeedBoostBlock(int x, int y) : Block(x, y) {
    isCollidable = false;
    this->setFillColor(sf::Color(255, 255, 255));
    this->Type = "SpeedBoostBlock";
    this->Activated = false;
}

void SpeedBoostBlock::onTouch(Player& whoTouched) {
    if (this->Activated == false) {
        whoTouched.setWalkSpeed(whoTouched.getWalkSpeed() + 2);
        this->Activated = true;
    }
}
