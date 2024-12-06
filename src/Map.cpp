//
// Created by jdnkw on 12/5/2024.
//

#include "Map.h"

#include <iostream>

#include "blocks/DisappearingBlock.h"
#include "blocks/FinishBlock.h"
#include "SFML/Graphics/Texture.hpp"

using sf::Texture;

Map::Map(const sf::Vector2u& windowSize) {
    this->loadMap(windowSize);
    this->loadBlockTextures();
    this->applyBlockTextures();
}

bool Map::loadBlockTextures() {
    bool success = true;

    const auto blockTexture = new Texture();
    blockTexture->loadFromFile("resources/blocks/Block.png");
    this->blockTextures.push_back(blockTexture);

    const auto finishBlockTexture = new Texture();
    finishBlockTexture->loadFromFile("resources/blocks/FinishBlock.png");
    this->blockTextures.push_back(finishBlockTexture);

    return success;
}

bool Map::applyBlockTextures() {
    bool success = true;

    for (int i = 0; i < this->blocks.size(); i++) {
        if (blocks[i]->Type == "Block") {
            blocks[i]->setTexture(this->blockTextures[0]);
        } else if (blocks[i]->Type == "FinishBlock") {
            blocks[i]->setTexture(this->blockTextures[1]);
        }
    }

    return success;
}

bool Map::loadMap(const sf::Vector2u& windowSize) {
    bool success = false;
    std::fstream mapFile("resources/mapData.txt");

    if (mapFile.is_open()) {
        success = true;

        std::string line;
        std::getline(mapFile, line); // discard header

        while (mapFile.good()) {
            std::stringstream ss;
            std::string blockType, x, y;

            std::getline(mapFile, line);
            ss.str(line);

            std::getline(ss, blockType, ',');
            std::getline(ss, x, ',');
            std::getline(ss, y);

            sf::Vector2f blockPosition(std::stoi(x) * 50, (windowSize.y - 50) - (std::stoi(y) * 50));

            if (blockType == "Block") {
                this->blocks.emplace_back(new Block(blockPosition.x, blockPosition.y));
                // std::cout << "Block at position " << x << "," << y << " pushed to map vector" << std::endl;
            } else if (blockType == "FinishBlock") {
                this->blocks.push_back(new FinishBlock(blockPosition.x, blockPosition.y));
                std::cout << "Block at position " << x << "," << y << " pushed to map vector" << std::endl;
            }else if (blockType == "DisappearingBlock") {
                this->blocks.push_back(new DisappearingBlock(blockPosition.x, blockPosition.y));
                std::cout<<"Block at position " << x << "," << y << " pushed to map vector" << std::endl;
            }
        }
    }

    return success;
    mapFile.close();
}
