//
// Created by jdnkw on 12/5/2024.
//

#include "Map.h"

Map::Map(const sf::Vector2u& windowSize) {
    this->loadMap(windowSize);
    //this->loadBlockTextures();
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

            if (blockType == "basicBlock") {
                this->blocks.emplace_back(blockPosition.x, blockPosition.y);
                // std::cout << "Block at position " << x << "," << y << " pushed to map vector" << std::endl;
            }
            // } else if (blockType == "finishBlock") {
            //     map.push_back(FinishBlock(blockPosition.x, blockPosition.y));
            // }
        }
    }

    return success;
    mapFile.close();
}
