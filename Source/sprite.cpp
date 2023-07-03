#include "sprite.hpp"
#include "utils/collision.hpp"

Sprite::Sprite(sf::Vector2f size, sf::Vector2f defaultPos, sf::Color color, float& _deltaTime) : 
				deltaTime(_deltaTime) {

	rect.setSize(size);
	rect.setPosition(defaultPos);
	rect.setFillColor(color);

	pos = defaultPos;

}

void Sprite::move(float x, float y) {
	pos.x += x * deltaTime;
	pos.y += y * deltaTime;

	rect.setPosition(pos);
}

void Sprite::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;

	rect.setPosition(pos);
}

void Sprite::setRotation(float angle) {
	rect.setRotation(angle);
}

bool Sprite::collide(Sprite otherSprite) {
	sf::Vector2f mtv;
	return testCollision(rect, otherSprite.rect, mtv);
}
