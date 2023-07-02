#include "weapons/sword.hpp"

	// MeleeWeapon(float _rotationSpeed, _rotationForce, _maxRotationForce, float _rotationMultiplicator);
Sword::Sword(float& _deltaTime) : MeleeWeapon(200, 4, 0.2, 100, 4, _deltaTime)  {
		// rect.setTextureRect(sf::IntRect(0, 0, 8, 4));
		// damageHitbox.setTextureRect(sf::IntRect(0, 0, 6, 4));
		
		sprite.rect.setSize(sf::Vector2f(12, 8));
		// damageHitboxRect.setSize(sf::Vector2f(12, 8));
		sprite.rect.setOrigin(-8, 4);
		// damageHitboxRect.setOrigin(-8, 4);
}
