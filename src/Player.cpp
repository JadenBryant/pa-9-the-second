#include "Player.h"
#include <iostream>

Player::Player(std::vector<Block> *blocks) {
    if (!texture.loadFromFile("resources/player.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    this->setTexture(texture);
    this->setPosition(200, 200);

    this->blocks = blocks;
    // CAMERA CODE
    this->Camera.setCenter(this->getPosition());
}

void Player::updatePhysics(sf::Time time) {
    float speed = 75.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = -speed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = speed;
    } else {
        velocity.x = 0;
    }

    float dt = time.asSeconds();
    float dy = 50 * dt;
    float dx = velocity.x * dt;
    auto position = this->getPosition();
    std::cout << "Player physics:" << position.y << " " << dt << " " << position.y + dy << std::endl;
    this->setPosition(position.x + dx, position.y + dy);
}
