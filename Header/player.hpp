#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(sf::Vector2i pos);
	void move(float horizontalValue, float verticalValue);
	sf::RectangleShape getRect();
	void handleMovement(float deltaTime);

	float horizontalSpeed;
	float verticalSpeed;

	static constexpr float ACCELERATION = 10,
									 			 DECELERATION = 8,
									 			 VELOCITY_CAP = 200;

private:
	sf::Rect<float> rect;
	sf::RectangleShape r;

};
