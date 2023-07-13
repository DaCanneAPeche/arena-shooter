#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "sprite.hpp"

class MeleeWeapon {
public:
	MeleeWeapon(float _rotationSpeed, float _maxRotationForce, float _rotationMultiplicator, 
			float _damage, float _knockback, sf::Vector2f size, float& _deltaTime, std::string assetName = "melee_weapons");
	MeleeWeapon(const MeleeWeapon& obj);
	void update(sf::Vector2f _entityPos, sf::Vector2i mousePos);
	/* sf::Sprite rect;
	sf::Sprite damageHitbox;
	sf::RectangleShape damageHitboxRect;
	sf::RenderTexture textureRect;
	sf::RenderTexture textureDamage; */

	Sprite sprite;

	float damage;
	float rotationForce;
	float knockback;
	sf::Vector2f entityPos;

protected:
	float rotation;
	float rotationSpeed;
	float maxRotationForce;
	float rotationMultiplicator;
	bool rotationDirection;
	float& deltaTime;
	float cursorRotation;

};
