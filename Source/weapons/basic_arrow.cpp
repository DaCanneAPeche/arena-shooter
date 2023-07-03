#include "weapons/basic_arrow.hpp"
#include "weapons/projectile.hpp"
#include <iostream>
#include "weapons/bow.hpp"


BasicArrow::BasicArrow(RangeWeaponInfos info, float& _deltaTime) : 
	Projectile(info, 10, 10, 10, sf::Vector2f(10, 2), _deltaTime) {
}

