#include "utils/move_diagonally.hpp"

#include <cmath>

sf::Vector2f moveDiagonally(float amount, sf::Vector2f source, Sprite sprite) {
	sf::Vector2f movement;
	float x = sprite.pos.x / 4 - source.x / 4,
				y = sprite.pos.y / 4 - source.y / 4;
	float hypotenuse = std::sqrt(x * x + y * y);

	movement.x = amount * x / hypotenuse;
	movement.y = amount * y / hypotenuse;

	return movement;
}

