//
// Created by jdnkw on 12/3/2024.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "SFML/System/Vector2.hpp"


class Camera {
public:
    Camera();
    ~Camera();

    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition();
    sf::Vector2f getViewportSize();

private:
    sf::Vector2f currentPosition;
    sf::Vector2f viewportSize;
};



#endif //CAMERA_H
