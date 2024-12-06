//
// Created by jdnkw on 12/5/2024.
//

#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include "blocks/Block.h"

class Map {
public:
    Map(const sf::Vector2u& windowSize);
    //bool loadBlockTextures();

    //std::vector<sf::Texture> blockTextures;
    std::vector<Block> blocks;
private:
    bool loadMap(const sf::Vector2u& windowSize);
};
