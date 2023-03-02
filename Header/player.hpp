#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(sf::Vector2i pos);
	void move(int horizontalValue, int verticalValue);
	sf::RectangleShape getRect();

private:
	sf::Rect<int> rect;
	sf::RectangleShape r;

};
