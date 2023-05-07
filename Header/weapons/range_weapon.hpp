#pragma once

#include "weapons/melee_weapon.hpp"
#include "timer.hpp"

class RangeWeapon : public MeleeWeapon
{
public:
	static constexpr float LOADING_TIME = 0.5;

	RangeWeapon(float _range, float _power, int _percing = 0);
	void checkLoading();

protected:
	float range,
				power,
				percing;

	int state;
	bool pressed;
	Timer loadingTimer;

};
