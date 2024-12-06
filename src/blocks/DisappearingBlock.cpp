//
// Created by jlusk on 12/5/2024.
//

#include "DisappearingBlock.h"


DisappearingBlock::DisappearingBlock(sf::Vector2f position) : Block(position), transparency(255),
isCollidable(true) {
    isCollidable = true;
    this->setFillColor(sf::Color(0, 255, 0, 255));
    this->Type = "DisappearingBlock";
}
DisappearingBlock::DisappearingBlock(int x, int y):
DisappearingBlock(sf::Vector2f(static_cast<float>(x), static_cast<float>(y))) {


}
void DisappearingBlock::onTouch(Player &whoTouched) {

if (isCollidable) {
    transparency -= 5.0f;
    if (transparency <= 0) {
        isCollidable = false;
    }
    sf::Color currColor = this->getFillColor();
    this->setFillColor(sf::Color(currColor.r, currColor.g, currColor.b, static_cast<sf::Uint8>(transparency)));
    }

}
