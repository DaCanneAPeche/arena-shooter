#pragma once
#include "weapons/range_weapon.hpp"
#include "weapons/range_weapon_info.hpp"

class Projectile
{
public:
	Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed);

protected:
	float damage,
				range,
				speed;

	RangeWeaponInfos weaponInfo;

};
