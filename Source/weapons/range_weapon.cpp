#include "weapons/range_weapon.hpp"
#include "SFML/Window/Mouse.hpp"

RangeWeapon::RangeWeapon(float _range, float _power, int _percing) : MeleeWeapon(1000, 1, 0, 1, 8)  {
	range = _range;
	power = _power;
	percing = _percing;

	state = 0;
	pressed = false;
}

void RangeWeapon::checkLoading() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (pressed) {
			if (loadingTimer.checkTime(false)) {
				if (state < 3) {
					std::cout << "LOADING" << std::endl;
					state++;
					loadingTimer.setTimer(LOADING_TIME);	
				}
				else {
					std::cout << "LOADED" << std::endl;
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
			std::cout << "SHOT" << std::endl;

		pressed = false;
		state = 0;
		loadingTimer.reset();
	}
}
