//
// Created by jdnkw on 12/5/2024.
//

#pragma once
#include "Block.h"

class FinishBlock : public Block {
    explicit FinishBlock(sf::Vector2f position);
    FinishBlock(int x, int y);
    void onTouch(Player& whoTouched) override;
};