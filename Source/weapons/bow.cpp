#include "weapons/bow.hpp"
#include "weapons/basic_arrow.hpp"
#include <memory>

Bow::Bow(float& _deltaTime) : RangeWeapon(_deltaTime, 10, 3, 1) {
		sprite.rect.setSize(sf::Vector2f(8, 10));
		// damageHitboxRect.setSize(sf::Vector2f(8, 12));
		sprite.rect.setOrigin(-6.5, 5);
		// damageHitboxRect.setOrigin(-7, 6);
}

// Bow::Bow(const Bow& obj) : RangeWeapon(_deltaTime, 10, 3, 1) {}

void Bow::onShot() {
	infos.entityPos = entityPos;
	infos.rotation = rotation;
	projectiles.push_back(std::make_shared<BasicArrow>(BasicArrow(infos, deltaTime)));
}
