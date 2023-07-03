#pragma once
#include "weapons/projectile.hpp"

class BasicArrow : public Projectile {

	public:
		BasicArrow(RangeWeaponInfos info, float& _deltaTime);
};
