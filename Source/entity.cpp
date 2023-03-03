#include "entity.hpp"
#include <iostream>

Entity::Entity(sf::Vector2i pos, sf::Vector2i size, sf::Color color) : rect(pos.x, pos.y, size.x, size.y) {

	r.setSize(sf::Vector2f(rect.width, rect.height));
	r.setFillColor(color);

}

void Entity::move(float horizontalValue, float verticalValue, float deltaTime) {
	rect.left += horizontalValue * deltaTime;
	rect.top += verticalValue * deltaTime;
}

sf::RectangleShape Entity::getRect() {
 
	r.setPosition(rect.left, rect.top);

	return r;
}

