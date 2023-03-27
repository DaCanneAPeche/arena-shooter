#include "weapons/melee_weapon.hpp"
#include <cmath>

void MeleeWeapon::init() {
	damageHitboxRect.setFillColor(sf::Color::Yellow);
}

void MeleeWeapon::update(float deltaTime, sf::Vector2f entityPos, sf::Vector2i mousePos) {
	damageHitbox.setPosition(entityPos.x, entityPos.y - 10);
	damageHitboxRect.setPosition(damageHitbox.getPosition());

	// rad * 180/pi = deg
	float rad = atan((entityPos.y - mousePos.y / 4) / (entityPos.x - mousePos.x / 4));

	if (mousePos.x / 4 > entityPos.x) rotation = rad * 180 / M_PI;
	else rotation = 180 + rad * 180 / M_PI;

	damageHitbox.setRotation(rotation);
	damageHitboxRect.setRotation(rotation);

}
