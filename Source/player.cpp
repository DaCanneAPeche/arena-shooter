#include "player.hpp"
#include <iostream>

Player::Player(sf::Vector2i pos) : rect(pos.x, pos.y, 8, 8) {

	r.setSize(sf::Vector2f(rect.width, rect.height));
	r.setFillColor(sf::Color::Green);

}

void Player::move(float horizontalValue, float verticalValue) {
	rect.left += horizontalValue;
	rect.top += verticalValue;
}

sf::RectangleShape Player::getRect() {
 
	r.setPosition(rect.left, rect.top);

	return r;
}

void Player::handleMovement(float deltaTime) {

    // Player's movement
    bool moving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        horizontalSpeed += ACCELERATION;
        moving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        horizontalSpeed -= ACCELERATION;
        moving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        verticalSpeed += ACCELERATION;
        moving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        verticalSpeed -= ACCELERATION;
        moving = true;
    }
        
    if (!moving && horizontalSpeed > 0) horizontalSpeed -= DECELERATION;
    else if (!moving && horizontalSpeed < 0) horizontalSpeed += DECELERATION;

    if (!moving && verticalSpeed > 0) verticalSpeed -= DECELERATION;
    else if (!moving && verticalSpeed < 0) verticalSpeed += DECELERATION;

    if (horizontalSpeed > VELOCITY_CAP) horizontalSpeed = VELOCITY_CAP;
    else if (horizontalSpeed < -1 * VELOCITY_CAP) 
        horizontalSpeed = -1 * VELOCITY_CAP;

    if (verticalSpeed > VELOCITY_CAP) verticalSpeed = VELOCITY_CAP;
    else if (verticalSpeed < -1 * VELOCITY_CAP) 
        verticalSpeed = -1 * VELOCITY_CAP;

    move(horizontalSpeed * deltaTime, 
            verticalSpeed * deltaTime);

}

