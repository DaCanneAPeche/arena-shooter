#pragma once

#include "SFML/Graphics.hpp"
#include "health_bar.hpp"
#include "sprite.hpp"
#include "weapons/sword.hpp"
#include "weapons/bow.hpp"

class Entity {
public:
	Entity(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float _life, float& _deltaTime);
	// sf::RectangleShape getRect();
	void damage(float amount);

	HealthBar healthBar;
	// sf::Rect<float> rect;
	float life;
	Sprite sprite;
	Sword meleeWeapon;
	Bow rangeWeapon;

private:

protected:
	void move(float horizontalValue, float verticalValue);
	// sf::Sprite sprite;
	// sf::RectangleShape r;
	float& deltaTime;

};
