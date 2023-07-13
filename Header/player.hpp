#pragma once

#include "SFML/Graphics.hpp"
#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/range_weapon.hpp"
#include <memory>

class Player : public Entity
{
public: 
	Player(sf::Vector2f pos, float& _deltaTime);
	// using Entity::Entity;
	void handleMovement();

	float horizontalSpeed;
	float verticalSpeed;

	static constexpr float ACCELERATION = 10,
									 			 DECELERATION = 8,
									 			 VELOCITY_CAP = 200;

	char weaponUsed;
	std::shared_ptr<MeleeWeapon> meleeWeapon;
	std::shared_ptr<RangeWeapon> rangeWeapon;

private:

};
