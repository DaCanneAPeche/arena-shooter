#include "weapons/bow.hpp"
#include "weapons/basic_arrow.hpp"
#include <memory>

Bow::Bow() : RangeWeapon(10, 3, 1) {
		damageHitbox.setScale(8, 12);
		damageHitboxRect.setSize(sf::Vector2f(8, 12));
		damageHitbox.setOrigin(-7, 5);
		damageHitboxRect.setOrigin(-7, 6);
}

Bow::Bow(const Bow& obj) : RangeWeapon(10, 3, 1) {}

void Bow::onShot() {
	BasicArrow arrow(infos);
}
