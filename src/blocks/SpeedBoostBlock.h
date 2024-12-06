//
// Created by jdnkw on 12/6/2024.
//

#pragma once
#include "Block.h"
#include "SFML/System/Vector2.hpp"

class SpeedBoostBlock : public Block {
public:
    explicit SpeedBoostBlock(sf::Vector2f position);
    SpeedBoostBlock(int x, int y);

    void onTouch(Player& whoTouched) override;
    bool Activated;
};

