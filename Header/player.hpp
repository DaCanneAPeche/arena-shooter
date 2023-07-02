#pragma once

#include "SFML/Graphics.hpp"
#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/bow.hpp"
#include "weapons/sword.hpp"

class Player : public Entity
{
public:
	// Player(sf::Vector2i pos);
	using Entity::Entity;
	void handleMovement();

	float horizontalSpeed;
	float verticalSpeed;

	static constexpr float ACCELERATION = 10,
									 			 DECELERATION = 8,
									 			 VELOCITY_CAP = 200;


private:

};
