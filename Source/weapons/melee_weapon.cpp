#include "weapons/melee_weapon.hpp"
#include <cmath>

MeleeWeapon::MeleeWeapon(float _rotationSpeed, float _maxRotationForce, 
		float _rotationMultiplicator, float _damage, float _knockback, sf::Vector2f size, float& _deltaTime,
		std::string assetName) : 
	sprite(size, sf::Vector2f(0, 0), sf::Color::Yellow, assetName, _deltaTime), deltaTime(_deltaTime) {

	rotationSpeed = _rotationSpeed;
	maxRotationForce = _maxRotationForce;
	rotationMultiplicator = _rotationMultiplicator;
	damage = _damage;
	knockback = _knockback;

	// damageHitboxRect.setFillColor(sf::Color::Yellow);
	rotation = 0;
	rotationForce = 1;

	sprite.setOrigin(-10, size.y / 2);
}

void MeleeWeapon::update(sf::Vector2f _entityPos, sf::Vector2i mousePos, sf::Vector2f cameraOffset) {
	entityPos = _entityPos;
	// Make a rotation between 0 and 360 deg
	if (rotation > 360) rotation -= 360;
	else if (rotation < 0) rotation += 360;

	sf::Vector2f origin = sprite.rect.getOrigin();
	sprite.setPosition(entityPos.x + cameraOffset.x - 2 * origin.x, entityPos.y + cameraOffset.y + origin.y);
	// damageHitboxRect.setPosition(damageHitbox.getPosition());
	// rect.setPosition(damageHitbox.getPosition());

	// angle as radiant
	float rad = atan((entityPos.y - mousePos.y / 4 ) /
			(entityPos.x - mousePos.x / 4));

	// angle as deg between 0 and 360
	if (mousePos.x / 4 > entityPos.x) cursorRotation = rad * 180 / M_PI;
	else cursorRotation = 180 + rad * 180 / M_PI;
	if (cursorRotation < 0) cursorRotation = 270 + 90 + cursorRotation;

	// calculate the difference between the two angles (found online)
	float a = cursorRotation - rotation;
	if (a > 180) a -= 360;
	else if (a < -180) a += 360;

	// change rotation
	float rotationChange = rotationSpeed * deltaTime;

	if (a < 0 && a + rotationChange < 0) {

		if (rotationDirection != 0) {
			rotationForce = 1;
			rotationDirection = 0;
		}

		rotationForce += rotationForce * rotationMultiplicator;
		if (rotationForce > maxRotationForce) rotationForce = maxRotationForce;
		if (rotation + rotationChange * rotationForce > cursorRotation)
			rotation -= rotationChange * rotationForce;
		else rotation = cursorRotation;
	}

	else if (a > 0 && (a - rotationChange) > 0) {

		if (rotationDirection != 1) {
			rotationForce = 1;
			rotationDirection = 1; 
		} 
		
		rotationForce += rotationForce * rotationMultiplicator;
		if (rotationForce > maxRotationForce) rotationForce = maxRotationForce;
		if (rotation + rotationChange * rotationForce < cursorRotation)
			rotation += rotationChange * rotationForce;
		else rotation = cursorRotation;
	}

	// apply rotation
	sprite.setRotation(rotation);
	// damageHitboxRect.setRotation(rotation);
	// rect.setRotation(rotation);

}
