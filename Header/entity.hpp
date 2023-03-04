#pragma once

#include "SFML/Graphics.hpp"
#include "health_bar.hpp"

class Entity {
public:
	Entity(sf::Vector2i pos, sf::Vector2i size, sf::Color color, float _life);
	sf::RectangleShape getRect();
	void damage(float amount);

	HealthBar healthBar;

private:
	sf::Rect<float> rect;
	sf::RectangleShape r;
	float life;

protected:
	void move(float horizontalValue, float verticalValue, float deltaTime);

};
