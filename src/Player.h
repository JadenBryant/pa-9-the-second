#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System/Time.hpp"

class Player : public sf::Sprite{
public:
    Player();
    ~Player()= default;
    void updatePhysics(sf::Time time);
private:
    sf::Texture texture;
};