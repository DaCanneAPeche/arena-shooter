#include "sprite.hpp"
#include "utils/collision.hpp"

Sprite::Sprite(sf::Vector2f size, sf::Vector2f defaultPos, sf::Color color, std::string assetName,
		float& _deltaTime, sf::Vector2f _offset) : 
				deltaTime(_deltaTime) {
	
	pos = defaultPos;
	offset = _offset;

	rect.setSize(size);
	rect.setPosition(defaultPos);
	rect.setFillColor(color);

	texture.loadFromFile("data/assets/" + assetName + ".png");
	sprite.setTexture(texture);
	sprite.setPosition(defaultPos);

}

void Sprite::move(float x, float y) {
	pos.x += x * deltaTime;
	pos.y += y * deltaTime;

	rect.setPosition(pos);
	sprite.setPosition(pos.x + offset.x, pos.y + offset.y);
}

void Sprite::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;

	rect.setPosition(pos);
	sprite.setPosition(pos.x + offset.x, pos.y + offset.y);
}

void Sprite::setRotation(float angle) {
	rect.setRotation(angle);
	sprite.setRotation(angle);
}

void Sprite::setOrigin(float x, float y) {
	rect.setOrigin(x, y);
	sprite.setOrigin(x, y);
}

bool Sprite::collide(Sprite otherSprite) {
	sf::Vector2f mtv;
	return testCollision(rect, otherSprite.rect, mtv);
}
