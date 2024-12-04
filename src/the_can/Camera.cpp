//
// Created by jdnkw on 12/3/2024.
//

#include "Camera.h"

Camera::Camera() {
}

void Camera::setPosition(sf::Vector2f newPosition) {
    this->currentPosition = newPosition;
}

sf::Vector2f Camera::getPosition() {
    return this->currentPosition;
}

sf::Vector2f Camera::getViewportSize() {
    return this->viewportSize;
}
