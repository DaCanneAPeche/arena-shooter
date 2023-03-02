#include "player.hpp"
#include <iostream>

Player::Player(sf::Vector2i pos) : rect(pos.x, pos.y, 8, 8) {

	r.setSize(sf::Vector2f(rect.width, rect.height));
	r.setFillColor(sf::Color::Green);

}

void Player::move(int horizontalValue, int verticalValue) {
	rect.left += horizontalValue;
	rect.top += verticalValue;
}

sf::RectangleShape Player::getRect() {
 
	r.setPosition(rect.left, rect.top);

	return r;
}

