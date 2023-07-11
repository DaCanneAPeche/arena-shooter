#pragma once

#include "SFML/Graphics.hpp"

class Sprite
{
public:
	Sprite (sf::Vector2f size, sf::Vector2f defaultPos, sf::Color color, float& _deltaTime);
	sf::RectangleShape rect;

	sf::Vector2f pos;
	void move(float x, float y);
	void setPosition(float x, float y);
	void setRotation(float angle);
	void setOrigin(float x, float y);
	bool collide(Sprite otherSprite);

private:
	float& deltaTime;

};
