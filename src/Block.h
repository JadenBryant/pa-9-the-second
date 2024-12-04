//
// Created by jdnkw on 12/3/2024.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"


class Block : public sf::RectangleShape {
public:
    Block();
    ~Block();
    void onTouch(Player& whoTouched);
private:
    sf::Sprite blockGraphic;
    sf::Vector2f position;
    bool isCollidable;
};



#endif //BLOCK_H
