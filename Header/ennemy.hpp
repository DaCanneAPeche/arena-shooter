#pragma once

#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "timer.hpp"

class Ennemy : public Entity
{
public:
	// using Entity::Entity;
	Ennemy(sf::Vector2f pos, float& _deltaTime);
	Timer timer;

	bool checkDamages(const MeleeWeapon& weapon);
	void moveToKb();

private:
	bool invincibility;
	sf::Vector2f kb;
	const float takenKnockback = 1;

	float horizontalKb,
				verticalKb;

	sf::Vector2f calculateKnockback(const MeleeWeapon& weapon);

};
