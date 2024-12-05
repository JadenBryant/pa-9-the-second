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
    auto position = getPosition();
    std::cout << "Player physics: " << position.y << " " << dt << " " << position.y + dy << std::endl;
    this->setPosition(position.x + dx, position.y + dy);

    auto playerBounds = getGlobalBounds();
    for (auto &block : *blocks) {
        auto blockBounds = block.getGlobalBounds();
        // std::cout << "Player test" << blockBounds.width << " " << blockBounds.height << " " << blockBounds.getPosition().x << " "<<  blockBounds.getPosition().y << std::endl;
        if (block.getGlobalBounds().intersects(playerBounds)) {
            dx = 0;
            dy = -dy;
            this->setPosition(position.x + dx, position.y + dy);
            // std::cout << "Player collision: " << position.y << " " << dt << " " << position.y + dy << std::endl;
        }
    }


}
