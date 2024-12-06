//
// Created by jlusk on 12/5/2024.
//

#include "DisappearingBlock.h"

#include <iostream>
#include <ostream>

//Constructor
DisappearingBlock::DisappearingBlock(sf::Vector2f position) : Block(position), transparency(255),
                                                              isCollidable(true) {
    isCollidable = true;
    this->setFillColor(sf::Color(0, 255, 0, 255));
    this->Type = "DisappearingBlock";
}
//Copy constructor
DisappearingBlock::DisappearingBlock(int x, int y):
DisappearingBlock(sf::Vector2f(static_cast<float>(x), static_cast<float>(y))) {


}

//This function will test to see if the player interacted with the block
void DisappearingBlock::onTouch(Player &whoTouched) {

if (isCollidable) {
    transparency -= 5.0f; // Slowly turn down the transparency..
    if (transparency <= 0) {
        isCollidable = false; // ..make it phasable if invisible.
    }
    sf::Color currColor = this->getFillColor();
    this->setFillColor(sf::Color(currColor.r, currColor.g, currColor.b, static_cast<sf::Uint8>(transparency)));
    }
    std::cout << "DisappearingBlock::onTouch" << std::endl;
}
