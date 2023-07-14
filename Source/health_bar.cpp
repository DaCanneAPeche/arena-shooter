#include "health_bar.hpp"
#include <iostream>

HealthBar::HealthBar(Sprite& _sprite, float& _life, float _maxLife) : 
										 life(_life), sprite(_sprite){
	maxLife = _maxLife;

	bgRect.setSize(sf::Vector2f(12, 1));
	bgRect.setFillColor(bgColor);

	fgRect.setSize(sf::Vector2f(12, 1));
	fgRect.setFillColor(fgColor);
}

void HealthBar::update(sf::Vector2f cameraOffset) {
	fgRect.setSize(sf::Vector2f((life * 12) / maxLife, 1));
	sf::Vector2f pos(sprite.pos.x - sprite.offset.x - cameraOffset.x - 2,
			sprite.pos.y - sprite.offset.y - cameraOffset.y - 4);

	bgRect.setPosition(pos);
	fgRect.setPosition(pos);

}
