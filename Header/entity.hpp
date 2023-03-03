#pragma once

#include "SFML/Graphics.hpp"

class Entity
{
public:
	Entity(sf::Vector2i pos, sf::Vector2i size, sf::Color color);
	void move(float horizontalValue, float verticalValue, float deltaTime);
	sf::RectangleShape getRect();

private:
	sf::Rect<float> rect;
	sf::RectangleShape r;

};
