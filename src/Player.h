#pragma once
#include "blocks/Block.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System/Time.hpp"

class Player : public sf::Sprite{
public:
    Player(std::vector<Block> *blocks);
    ~Player()= default;
    void updatePhysics(sf::Time time);

    sf::View Camera;
private:
    sf::Vector2f velocity;
    sf::Texture texture;
    std::vector<Block> *blocks;
};