#pragma once

#include "SFML/Graphics.hpp"
#include "health_bar.hpp"

class Entity {
public:
	Entity(sf::Vector2i pos, sf::Vector2i size, sf::Color color, float _life);
	sf::RectangleShape getRect();
	void damage(float amount);

	HealthBar healthBar;
	sf::Rect<float> rect;

private:
	float life;

protected:
	void move(float horizontalValue, float verticalValue, float deltaTime);
	sf::Sprite sprite;
	sf::RectangleShape r;

};
