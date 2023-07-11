#pragma once

#include "weapons/melee_weapon.hpp"
#include "timer.hpp"
#include "weapons/range_weapon_info.hpp"
#include <memory>
#include <vector>
#include "weapons/projectile.hpp"

class EntityCreator;

class RangeWeapon : public MeleeWeapon
{
public:
	static constexpr float LOADING_TIME = 0.5;

	RangeWeapon(float& _deltaTime, float _range, float _power, int _percing, sf::Vector2f size);
	RangeWeapon(const RangeWeapon& obj);
	void checkLoading(EntityCreator& entityCreator);
	void checkProjectiles();
	std::vector<std::shared_ptr<Projectile>> projectiles;

protected:
	RangeWeaponInfos infos;

	bool pressed;
	int state;
	Timer loadingTimer;

	void onLoad();
	void onShot(EntityCreator& entityCreator);

};
