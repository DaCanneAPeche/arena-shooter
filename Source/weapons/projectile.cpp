#include "weapons/projectile.hpp"
#include "weapons/bow.hpp"
#include "utils/move_diagonally.hpp"
#include <iostream>

Projectile::Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed, sf::Vector2f size, 
		float& _deltaTime) :
          sprite(size, sf::Vector2f(info.entityPos.x, info.entityPos.y), sf::Color::Magenta, _deltaTime),
					deltaTime(_deltaTime) {
	damage = _damage;
	range = _range;
	speed = _speed;

	weaponInfo = info;
	
	sprite.setPosition(sprite.pos.x + 4, sprite.pos.y + 4);
	sprite.setRotation(weaponInfo.rotation);
}

void Projectile::update() {
	// sf::Vector2f movement = moveDiagonally(speed, weaponInfo.entityPos, sprite);
	sf::Vector2f movement = moveDiagonallyByAngle(speed, weaponInfo.rotation, sprite);
	sprite.move(movement.x, movement.y);

}

