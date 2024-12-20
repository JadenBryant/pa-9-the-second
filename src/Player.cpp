#include "Player.h"
#include <iostream>

Player::Player(std::vector<Block*> *blocks) {
    if (!texture.loadFromFile("resources/player.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    setTexture(texture);
    setPosition(200, 200);
    setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    this->blocks = blocks;

    // CAMERA CODE
    this->Camera.setCenter(this->getPosition());

    // ATTRIBUTES
    this->walkSpeed = 3;
}

// run every frame to manage physics, since player is the only thing moving
// physics kinda only revolves around it
void Player::updatePhysics(sf::Time time) {
    auto position = getPosition();
    float moveSpeed = (this->walkSpeed * 100.0f), jumpSpeed = 400.0f;
    float dt = time.asSeconds();
    float dg = 200 * dt;

    //side movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = -moveSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = moveSpeed;
    } else {
        velocity.x = 0;
    }

    // vertical stuff
    velocity.y += dg;
    if (velocity.y > 0)
        velocity.y = 0;

    bool falling = true;
    for (auto &block : *blocks) {
        auto blockBounds = block->getGlobalBounds();
        sf::Vector2f testPoint1(position.x + 30, position.y + texture.getSize().y / 2 + 2);
        sf::Vector2f testPoint2(position.x - 30, position.y + texture.getSize().y / 2 + 2);
        if (block->getGlobalBounds().contains(testPoint1) || block->getGlobalBounds().contains(testPoint2)) {
            falling = false;
            break;
        }
    }

    //jump code
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && falling == false) {
        std::cout << "Jump" << std::endl;
        velocity.y = -jumpSpeed;
    }

    // use the dt to calculate our movement amount so we move a constant amount per time
    float dx = velocity.x * dt;
    float dy = velocity.y * dt;
    // std::cout << "Player physics: " << position.y << " " << dt << " " << position.y + dg << std::endl;
    if (falling) {

        dy += dg;
    }
    setPosition(position.x + dx, position.y + dy);

    auto playerBounds = getGlobalBounds();
    for (auto &block : *blocks) {
        auto blockBounds = block->getGlobalBounds();
        // std::cout << "Player test" << blockBounds.width << " " << blockBounds.height << " " << blockBounds.getPosition().x << " "<<  blockBounds.getPosition().y << std::endl;
        if (block->getGlobalBounds().intersects(playerBounds)) {
            if (block->isCollidable) {
                velocity.y = 0;
                setPosition(position.x, position.y - 1);
            }
            block->onTouch(*this);
            break;
            // std::cout << "Player collision: " << position.y << " " << dt << " " << position.y + dy << std::endl;
        }
    }
}

const int Player::getWalkSpeed() {
    return this->walkSpeed;
}

void Player::setWalkSpeed(int walkSpeed) {
    this->walkSpeed = walkSpeed;
}

