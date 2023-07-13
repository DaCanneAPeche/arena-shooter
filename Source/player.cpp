#include "player.hpp"
#include <iostream>


Player::Player(sf::Vector2f pos, float& _deltaTime) :
    Entity(pos, sf::Vector2f(8, 8), sf::Color::Red, 400, "player", _deltaTime, sf::Vector2f(-8, 0)) {

}

void Player::handleMovement() {

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
    if (!movingHorizontaly && horizontalSpeed > 0) {
        if (horizontalSpeed - DECELERATION > 0) horizontalSpeed -= DECELERATION;
        else horizontalSpeed = 0;
    }
    else if (!movingHorizontaly && horizontalSpeed < 0) {
        if (horizontalSpeed + DECELERATION < 0) horizontalSpeed += DECELERATION;
        else horizontalSpeed = 0;
    }
    // else if (!movingHorizontaly && horizontalSpeed < 0) horizontalSpeed += DECELERATION;

    // if (!movingVerticaly && verticalSpeed > 0) verticalSpeed -= DECELERATION;
    // else if (!movingVerticaly && verticalSpeed < 0) verticalSpeed += DECELERATION;

    if (!movingVerticaly && verticalSpeed > 0) {
        if (verticalSpeed - DECELERATION > 0) verticalSpeed -= DECELERATION;
        else verticalSpeed = 0;
    }
    else if (!movingVerticaly && verticalSpeed < 0) {
        if (verticalSpeed + DECELERATION < 0) verticalSpeed += DECELERATION;
        else verticalSpeed = 0;
    }

    // Velocity cap
    if (horizontalSpeed > VELOCITY_CAP) horizontalSpeed = VELOCITY_CAP;
    else if (horizontalSpeed < -1 * VELOCITY_CAP) 
        horizontalSpeed = -1 * VELOCITY_CAP;

    if (verticalSpeed > VELOCITY_CAP) verticalSpeed = VELOCITY_CAP;
    else if (verticalSpeed < -1 * VELOCITY_CAP) 
        verticalSpeed = -1 * VELOCITY_CAP;


    move(horizontalSpeed, 
            verticalSpeed);

}

