#include "weapons/range_weapon.hpp"
#include "SFML/Window/Mouse.hpp"
// #include "weapons/bow.hpp"
#include <algorithm>
#include "entity_creator.hpp"

RangeWeapon::RangeWeapon(float& _deltaTime, float _range, float _power, int _percing, sf::Vector2f size) : 
	MeleeWeapon(1000, 1, 0, 1, 8, size, _deltaTime, "range_weapons"),
						 infos{_range, _power, _percing} {

	state = 0;
	pressed = false;
}

void RangeWeapon::checkLoading(EntityCreator& entityCreator) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (pressed) {
			if (loadingTimer.checkTime(false)) {
				if (state < 3) {
					onLoad();
					state++;
					loadingTimer.setTimer(LOADING_TIME);	
				}
			}
		}
		else {
			pressed = true;
			loadingTimer.setTimer(LOADING_TIME);
		}
	}
	else {
		
		if (state >= 3)
			onShot(entityCreator);

		pressed = false;
		state = 0;
		loadingTimer.reset();
	}
}

void RangeWeapon::checkProjectiles() {
	for (const auto& projectile : projectiles) {
		if ((projectile->getTraveledDistance() >= projectile->range * infos.range) || 
				(projectile->percing < 0)) {

			projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile),
					projectiles.end());

		}
	}
}

void RangeWeapon::onLoad() {
}

void RangeWeapon::onShot(EntityCreator& entityCreator) {
	infos.entityPos = sprite.pos;
	infos.rotation = cursorRotation;
	std::cout << sprite.pos.x << std::endl;
	projectiles.push_back(entityCreator.getProjectile("basic_arrow", infos));
}
