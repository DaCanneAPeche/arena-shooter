#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class MeleeWeapon {
public:
	MeleeWeapon(float _rotationSpeed, float _maxRotationForce, float _rotationMultiplicator, 
			float _damage);
	void update(float deltaTime, sf::Vector2f entiyPos, sf::Vector2i mousePos);
	sf::Sprite rect;
	sf::Sprite damageHitbox;
	sf::RectangleShape damageHitboxRect;
	sf::RenderTexture textureRect;
	sf::RenderTexture textureDamage;

	float damage;
	float rotationForce;

protected:
	float rotation;
	float rotationSpeed;
	float maxRotationForce;
	float rotationMultiplicator;
	bool rotationDirection;

};
