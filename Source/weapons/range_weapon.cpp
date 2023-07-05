#include "weapons/range_weapon.hpp"
#include "SFML/Window/Mouse.hpp"
#include "weapons/bow.hpp"
#include <algorithm>

RangeWeapon::RangeWeapon(float& _deltaTime, float _range, float _power, int _percing) : 
	MeleeWeapon(1000, 1, 0, 1, 8, _deltaTime),
						 infos{_range, _power, _percing} {

	state = 0;
	pressed = false;
}

void RangeWeapon::checkLoading() {
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
			onShot();

		pressed = false;
		state = 0;
		loadingTimer.reset();
	}
}

void RangeWeapon::checkProjectiles() {
	for (const auto& projectile : projectiles) {
		if (projectile->getTraveledDistance() >= projectile->range * infos.range) {

			projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile),
					projectiles.end());

		}
	}
}

void RangeWeapon::onLoad() {
	std::cout << "Loading not implemented" << std::endl;
}

void RangeWeapon::onShot() {
	std::cout << "Shot not implemented" << std::endl;
}
