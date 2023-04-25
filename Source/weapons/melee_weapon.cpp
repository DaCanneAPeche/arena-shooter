#include "weapons/melee_weapon.hpp"
#include <cmath>

MeleeWeapon::MeleeWeapon(float _rotationSpeed, float _maxRotationForce, float _rotationMultiplicator, 
			float _damage) {

	rotationSpeed = _rotationSpeed;
	maxRotationForce = _maxRotationForce;
	rotationMultiplicator = _rotationMultiplicator;
	damage = _damage;

	damageHitboxRect.setFillColor(sf::Color::Yellow);
	rotation = 0;
	rotationForce = 1;
}

void MeleeWeapon::update(float deltaTime, sf::Vector2f entityPos, sf::Vector2i mousePos) {
	// Make a rotation between 0 and 360 deg
	if (rotation > 360) rotation -= 360;
	else if (rotation < 0) rotation += 360;

	float cursorRotation;
	sf::Vector2f origin = damageHitbox.getOrigin();
	damageHitbox.setPosition(entityPos.x - origin.x/2, entityPos.y + origin.y);
	damageHitboxRect.setPosition(damageHitbox.getPosition());
	rect.setPosition(damageHitbox.getPosition());

	// angle as radiant
	float rad = atan((entityPos.y - mousePos.y / 4) / (entityPos.x - mousePos.x / 4));

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
		rotation -= rotationChange * rotationForce;
	}

	else if (a > 0 && (a - rotationChange) > 0) {

		if (rotationDirection != 1) {
			rotationForce = 1;
			rotationDirection = 1; 
		} 
		
		rotationForce += rotationForce * rotationMultiplicator;
		if (rotationForce > maxRotationForce) rotationForce = maxRotationForce;
		rotation += rotationChange * rotationForce;
	}

	// apply rotation
	damageHitbox.setRotation(rotation);
	damageHitboxRect.setRotation(rotation);
	rect.setRotation(rotation);

}
