//
// Created by jdnkw on 12/6/2024.
//

#pragma once
#include "Block.h"
#include "SFML/System/Vector2.hpp"

class KillBlock : public Block {
public:
    explicit KillBlock(sf::Vector2f position);
    KillBlock(int x, int y);

    void onTouch(Player& whoTouched) override;
    bool* isGameOver;
};