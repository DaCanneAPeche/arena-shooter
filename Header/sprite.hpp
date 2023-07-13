#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class Sprite
{
public:
	Sprite (sf::Vector2f size, sf::Vector2f defaultPos, sf::Color color, std::string assetName, 
			float& _deltaTime, sf::Vector2f _offset = sf::Vector2f(0, 0));
	sf::RectangleShape rect;
	sf::Sprite sprite;

	sf::Vector2f pos;
	void move(float x, float y);
	void setPosition(float x, float y);
	void setRotation(float angle);
	void setOrigin(float x, float y);
	bool collide(Sprite otherSprite);

private:
	float& deltaTime;
	sf::Texture texture;
	sf::Vector2f offset;

};
