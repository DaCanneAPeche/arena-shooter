#pragma once

#include "SFML/Graphics.hpp"
#include "sprite.hpp"

class HealthBar {
public:
	HealthBar(Sprite& _sprite, float& _life, float _maxLife);
	void update(sf::Vector2f cameraOffset);

	sf::RectangleShape bgRect;
	sf::RectangleShape fgRect;

	const sf::Color bgColor = sf::Color::Black;
	const sf::Color fgColor = sf::Color::Green;

private:
	float maxLife;
	float& life;
	Sprite& sprite;

};
