#include "weapons/projectile.hpp"
#include "weapons/bow.hpp"

Projectile::Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed, sf::Vector2f size, 
		float& _deltaTime) :
          sprite(size, sf::Vector2f(info.entityPos.x, info.entityPos.y), sf::Color::Magenta, _deltaTime),
					deltaTime(_deltaTime) {
	damage = _damage;
	range = _range;
	speed = _speed;

	weaponInfo = info;
}

