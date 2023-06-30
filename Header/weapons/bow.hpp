#pragma once
#include "weapons/range_weapon.hpp"

class Bow : public RangeWeapon {
public:
	Bow();
	Bow(const Bow&);

private:
	virtual void onShot() override;
};
