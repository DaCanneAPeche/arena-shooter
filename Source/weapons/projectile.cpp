#include "weapons/projectile.hpp"
#include "weapons/bow.hpp"

Projectile::Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed) {
	damage = _damage;
	range = _range;
	speed = _speed;

	weaponInfo = info;
}

