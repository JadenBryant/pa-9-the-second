#include "Player.h"
#include <iostream>

Player::Player() {
    if (!texture.loadFromFile("resources/player.png"))
    {
        std::cerr << "Failed to load texture" << std::endl;
    }
    this->setTexture(texture);
    this->setPosition(200, 200);

    // CAMERA CODE
    this->Camera.setCenter(this->getPosition());
}

void Player::updatePhysics(sf::Time time) {
    float dt = time.asSeconds();
    float dy = 50 * dt;
    auto position = this->getPosition();
    std::cout << position.y << " " << dt << " " << position.y + dy << std::endl;
    this->setPosition(position.x, position.y + dy);
}
