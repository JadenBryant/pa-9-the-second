//
// Created by jdnkw on 12/5/2024.
//

#include "FinishBlock.h"

FinishBlock::FinishBlock(sf::Vector2f position) : Block(position) {
    isCollidable = false;
}

void FinishBlock::onTouch(Player& whoTouched) {

}