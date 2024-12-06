//
// Created by jdnkw on 12/6/2024.
//

#pragma once
#include "Block.h"
#include "SFML/System/Vector2.hpp"

class SlowBlock : public Block {
public:
    explicit SlowBlock(sf::Vector2f position);
    SlowBlock(int x, int y);

    void onTouch(Player& whoTouched) override;
    bool Activated; // prevent block from being used more than once
};

