#include "utils/move_diagonally.hpp"
#include <iostream>

#include <cmath>
#include <math.h>

sf::Vector2f moveDiagonally(float amount, sf::Vector2f source, Sprite sprite) {
	sf::Vector2f movement;
	float x = sprite.pos.x / 4 - source.x / 4,
				y = sprite.pos.y / 4 - source.y / 4;
	float hypotenuse = std::sqrt(x * x + y * y);

	movement.x = amount * x / hypotenuse;
	movement.y = amount * y / hypotenuse;

	return movement;
}

sf::Vector2f moveDiagonallyByAngle(float amount, float angle, Sprite sprite) {
	sf::Vector2f movement;

	float radAngle = angle * M_PI / 180;

	movement.x = std::cos(radAngle) * amount;
	movement.y = std::sin(radAngle) * amount;

	return movement;
}

