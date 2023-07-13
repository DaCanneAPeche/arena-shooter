#include "weapons/projectile.hpp"
// #include "weapons/bow.hpp"
#include "utils/move_diagonally.hpp"
#include <iostream>
#include <cmath>

Projectile::Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed, sf::Vector2f size,
		float& _deltaTime) :
          sprite(size, sf::Vector2f(info.entityPos.x, info.entityPos.y), sf::Color::Magenta, "projectiles",
							_deltaTime),
					deltaTime(_deltaTime) {
	damage = _damage;
	range = _range;
	speed = _speed;

	weaponInfo = info;
	percing = weaponInfo.percing;
	
	sprite.setPosition(sprite.pos.x + 4, sprite.pos.y + 4);
	sprite.setRotation(weaponInfo.rotation);
}

void Projectile::update() {
	// sf::Vector2f movement = moveDiagonally(speed, weaponInfo.entityPos, sprite);
	sf::Vector2f movement = moveDiagonallyByAngle(speed, weaponInfo.rotation, sprite);
	sprite.move(movement.x, movement.y);

}

float Projectile::getTraveledDistance() {
	float x = sprite.pos.x - weaponInfo.entityPos.x,
				y = sprite.pos.y - weaponInfo.entityPos.y;

	return std::sqrt(std::abs(x * x + y * y));
}

