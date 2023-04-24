#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class MeleeWeapon {
public:
	void init();
	void update(float deltaTime, sf::Vector2f entiyPos, sf::Vector2i mousePos);
	sf::Sprite rect;
	sf::Sprite damageHitbox;
	sf::RectangleShape damageHitboxRect;
	sf::RenderTexture textureRect;
	sf::RenderTexture textureDamage;

protected:
	float rotation;
	float rotationSpeed;
	float rotationForce;
	float maxRotationForce;
	float rotationMultiplicator;
	bool rotationDirection;

};
