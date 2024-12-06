//
// Created by jdnkw on 12/5/2024.
//

#include "Map.h"

#include <iostream>

#include "blocks/DisappearingBlock.h"
#include "blocks/FinishBlock.h"
#include "blocks/KillBlock.h"
#include "blocks/SlowBlock.h"
#include "blocks/SpeedBoostBlock.h"
#include "SFML/Graphics/Texture.hpp"

using sf::Texture;

Map::Map(const sf::Vector2u& windowSize) {
    this->loadMap(windowSize);
    this->loadBlockTextures();
    this->applyBlockTextures();
}

bool Map::loadBlockTextures() {
    bool success = true;

    // LOADING EACH TEXTURE AND STORING THEM IN A VECTOR
    
    const auto blockTexture = new Texture();
    blockTexture->loadFromFile("resources/blocks/Block.png");
    this->blockTextures.push_back(blockTexture);

    const auto finishBlockTexture = new Texture();
    finishBlockTexture->loadFromFile("resources/blocks/FinishBlock.png");
    this->blockTextures.push_back(finishBlockTexture);

    const auto speedBlockTexture = new Texture();
    speedBlockTexture->loadFromFile("resources/blocks/SpeedBoostBlock.png");
    this->blockTextures.push_back(speedBlockTexture);

    const auto slowBlockTexture = new Texture();
    slowBlockTexture->loadFromFile("resources/blocks/SlowBlock.png");
    this->blockTextures.push_back(slowBlockTexture);

    const auto killBlockTexture = new Texture();
    killBlockTexture->loadFromFile("resources/blocks/KillBlock.png");
    this->blockTextures.push_back(killBlockTexture);

    return success;
}

bool Map::applyBlockTextures() {
    bool success = true;

    // ITERATING THROUGH LOADED BLOCKS AND APPLYING TEXTURES
    
    for (int i = 0; i < this->blocks.size(); i++) {
        if (blocks[i]->Type == "Block") {
            blocks[i]->setTexture(this->blockTextures[0]);
        } else if (blocks[i]->Type == "FinishBlock") {
            blocks[i]->setTexture(this->blockTextures[1]);
        } else if (blocks[i]->Type == "SpeedBoostBlock") {
            blocks[i]->setTexture(this->blockTextures[2]);
        } else if (blocks[i]->Type == "SlowBlock") {
            blocks[i]->setTexture(this->blockTextures[3]);
        } else if (blocks[i]->Type == "KillBlock") {
            blocks[i]->setTexture(this->blockTextures[4]);
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

            sf::Vector2f blockPosition(std::stoi(x) * 50, (windowSize.y - 50) - (std::stoi(y) * 50)); // Bottom of window (if player view isn't updated)

            // Instantiating appropriate block per type
            if (blockType == "Block") {
                this->blocks.emplace_back(new Block(blockPosition.x, blockPosition.y));
            } else if (blockType == "FinishBlock") {
                this->blocks.push_back(new FinishBlock(blockPosition.x, blockPosition.y));
            } else if (blockType == "DisappearingBlock") {
                this->blocks.push_back(new DisappearingBlock(blockPosition.x, blockPosition.y));
            } else if (blockType == "SpeedBoostBlock") {
                this->blocks.push_back(new SpeedBoostBlock(blockPosition.x, blockPosition.y));
            } else if (blockType == "SlowBlock") {
                this->blocks.push_back(new SlowBlock(blockPosition.x, blockPosition.y));
            } else if (blockType == "KillBlock") {
                this->blocks.push_back(new KillBlock(blockPosition.x, blockPosition.y));
            }
        }
    }

    return success;
    mapFile.close();
}
