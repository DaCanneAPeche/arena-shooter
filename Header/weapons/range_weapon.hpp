#pragma once

#include "weapons/melee_weapon.hpp"
#include "timer.hpp"
#include "weapons/range_weapon_info.hpp"
#include <memory>
#include <vector>
#include "weapons/basic_arrow.hpp"

class RangeWeapon : public MeleeWeapon
{
public:
	static constexpr float LOADING_TIME = 0.5;

	RangeWeapon(float& _deltaTime, float _range, float _power, int _percing = 0);
	RangeWeapon(const RangeWeapon& obj);
	void checkLoading();
	void checkProjectiles();
	std::vector<std::shared_ptr<BasicArrow>> projectiles;

protected:
	RangeWeaponInfos infos;

	bool pressed;
	int state;
	Timer loadingTimer;

	virtual void onLoad();
	virtual void onShot();

};
