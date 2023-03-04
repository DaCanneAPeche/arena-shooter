#pragma once

#include "SFML/Graphics.hpp"

class HealthBar {
public:
	HealthBar(float& entityPosX, float& entityPosY, float& _life, float _maxLife);
	void update();

	sf::RectangleShape bgRect;
	sf::RectangleShape fgRect;

	const sf::Color bgColor = sf::Color::Black;
	const sf::Color fgColor = sf::Color::Green;

private:
	float maxLife;
	float& life;

	float& entityPosX;
	float& entityPosY;

};
