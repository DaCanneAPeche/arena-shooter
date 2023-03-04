#include "player.hpp"
#include <iostream>

void Player::handleMovement(float deltaTime) {

    // Player's movement
    bool movingHorizontaly = false;
    bool movingVerticaly = false;

    // Key handling
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        horizontalSpeed += ACCELERATION;
        movingHorizontaly = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        horizontalSpeed -= ACCELERATION;
        movingHorizontaly = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        verticalSpeed += ACCELERATION;
        movingVerticaly = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        verticalSpeed -= ACCELERATION;
        movingVerticaly = true;
    }

    // Decelration    
    if (!movingHorizontaly && horizontalSpeed > 0) horizontalSpeed -= DECELERATION;
    else if (!movingHorizontaly && horizontalSpeed < 0) horizontalSpeed += DECELERATION;

    if (!movingVerticaly && verticalSpeed > 0) verticalSpeed -= DECELERATION;
    else if (!movingVerticaly && verticalSpeed < 0) verticalSpeed += DECELERATION;

    // Velocity cap
    if (horizontalSpeed > VELOCITY_CAP) horizontalSpeed = VELOCITY_CAP;
    else if (horizontalSpeed < -1 * VELOCITY_CAP) 
        horizontalSpeed = -1 * VELOCITY_CAP;

    if (verticalSpeed > VELOCITY_CAP) verticalSpeed = VELOCITY_CAP;
    else if (verticalSpeed < -1 * VELOCITY_CAP) 
        verticalSpeed = -1 * VELOCITY_CAP;


    move(horizontalSpeed, 
            verticalSpeed,
            deltaTime);

}

