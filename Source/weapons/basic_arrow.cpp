#include "weapons/basic_arrow.hpp"
#include "weapons/projectile.hpp"
#include <iostream>
#include "weapons/bow.hpp"


BasicArrow::BasicArrow(RangeWeaponInfos info) : 
	Projectile(info, 10, 10, 10) {
}

