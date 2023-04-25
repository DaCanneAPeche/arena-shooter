#include "weapons/sword.hpp"

	// MeleeWeapon(float _rotationSpeed, _rotationForce, _maxRotationForce, float _rotationMultiplicator);
Sword::Sword() : MeleeWeapon(200, 4, 0.2, 100)  {
		// rect.setTextureRect(sf::IntRect(0, 0, 8, 4));
		// damageHitbox.setTextureRect(sf::IntRect(0, 0, 6, 4));
		// TODO: rect is the texture
		
		damageHitbox.setScale(12, 8);
		damageHitboxRect.setSize(sf::Vector2f(12, 8));
		damageHitbox.setOrigin(-8, 4);
		damageHitboxRect.setOrigin(-8, 4);
}
