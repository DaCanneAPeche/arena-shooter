#include "health_bar.hpp"
#include <iostream>

HealthBar::HealthBar(float& _entityPosX, float& _entityPosY, float& _life, float _maxLife) : 
										 life(_life), entityPosX(_entityPosX), entityPosY(_entityPosY) {
	maxLife = _maxLife;

	bgRect.setSize(sf::Vector2f(12, 1));
	bgRect.setFillColor(bgColor);

	fgRect.setSize(sf::Vector2f(12, 1));
	fgRect.setFillColor(fgColor);
}

void HealthBar::update() {
	fgRect.setSize(sf::Vector2f((life * 12) / maxLife, 1));
	sf::Vector2f pos(entityPosX - 2, entityPosY - 4);

	bgRect.setPosition(pos);
	fgRect.setPosition(pos);

}
