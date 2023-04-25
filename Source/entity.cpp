#include "entity.hpp"
#include <iostream>

Entity::Entity(sf::Vector2i pos, sf::Vector2i size, sf::Color color, float _life) : 
	rect(pos.x, pos.y, size.x, size.y), healthBar(rect.left, rect.top, life, _life) {

	sprite.setScale(size.x, size.y);
	sprite.setPosition(pos.x, pos.y);
	r.setSize(sf::Vector2f(rect.width, rect.height));
	r.setFillColor(color);
	life = _life;

}

void Entity::move(float horizontalValue, float verticalValue, float deltaTime) {
	rect.left += horizontalValue * deltaTime;
	rect.top += verticalValue * deltaTime;

	sprite.setPosition(rect.left, rect.top);
}

sf::RectangleShape Entity::getRect() {
 
	r.setPosition(rect.left, rect.top);

	return r;
}

void Entity::damage(float amount) {
	life -= amount;
}

