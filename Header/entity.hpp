#pragma once

#include "SFML/Graphics.hpp"
#include "health_bar.hpp"
#include "sprite.hpp"
#include "timer.hpp"
#include <string>

class Entity {
public:
	Entity(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float _life,
			std::string assetName, float& _deltaTime, sf::Vector2f offset = sf::Vector2f(0, 0));
	// sf::RectangleShape getRect();
	float damage(float amount);

	HealthBar healthBar;
	// sf::Rect<float> rect;
	float life;
	Sprite sprite;

private:

protected:
	void move(float horizontalValue, float verticalValue);
	// sf::Sprite sprite;
	// sf::RectangleShape r;
	float& deltaTime;
	Timer timer;
	bool invincibility;

};
