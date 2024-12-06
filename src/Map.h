//
// Created by jdnkw on 12/5/2024.
//

#pragma once

#include <vector>
#include "blocks/Block.h"

class Map {
public:
    Map();
    bool loadMap();
private:
    std::vector<Block> blocks;
};
