#pragma once

#include "weapons/melee_weapon.hpp"
#include "timer.hpp"
#include "weapons/range_weapon_info.hpp"

class RangeWeapon : public MeleeWeapon
{
public:
	static constexpr float LOADING_TIME = 0.5;

	RangeWeapon(float& _deltaTime, float _range, float _power, int _percing = 0);
	RangeWeapon(const RangeWeapon& obj);
	void checkLoading();

protected:
	RangeWeaponInfos infos;

	bool pressed;
	int state;
	Timer loadingTimer;

	virtual void onLoad();
	virtual void onShot();

};
