#include "entity.hpp"
#include <iostream>

Entity::Entity(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float _life, std::string assetName,
		float& _deltaTime, sf::Vector2f offset) : 
	sprite(size, pos, color, assetName, _deltaTime, offset), 
	healthBar(sprite.pos.x, sprite.pos.y, life, _life), 
	deltaTime(_deltaTime) {

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

float Entity::damage(float amount) {
	life -= amount;
	invincibility = true;
	timer.setTimer(1);

	return amount;
}

