#pragma once
#include "weapons/range_weapon_info.hpp"
#include "sprite.hpp"

class Projectile
{
public:
	Projectile(RangeWeaponInfos info, float _damage, float _range, float _speed, sf::Vector2f size,
			float& _deltaTime);
	Sprite sprite;
	void update();
	RangeWeaponInfos weaponInfo;
	float damage,
				range;
	float getTraveledDistance();

	int percing;

protected:
	float speed;
	float& deltaTime;


};
