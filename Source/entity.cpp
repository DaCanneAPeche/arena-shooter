#include "entity.hpp"
#include <iostream>

Entity::Entity(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float _life, float& _deltaTime) : 
	sprite(size, pos, color, _deltaTime), 
	healthBar(sprite.pos.x, sprite.pos.y, life, _life), 
	deltaTime(_deltaTime), meleeWeapon(_deltaTime), rangeWeapon(_deltaTime) {

	// sprite.setScale(size.x, size.y);
	// sprite.setPosition(pos.x, pos.y);
	// r.setSize(sf::Vector2f(rect.width, rect.height));
	// r.setFillColor(color);
	life = _life;

}

void Entity::move(float horizontalValue, float verticalValue) {
	// rect.left += horizontalValue * deltaTime;
	// rect.top += verticalValue * deltaTime;

	// sprite.setPosition(rect.left, rect.top);
	
	sprite.move(horizontalValue, verticalValue);
}

/* sf::RectangleShape Entity::getRect() {
 
	r.setPosition(rect.left, rect.top);

	return r;
}
*/

void Entity::damage(float amount) {
	life -= amount;
}

