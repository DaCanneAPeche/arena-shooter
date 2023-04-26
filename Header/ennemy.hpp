#pragma once

#include "entity.hpp"
#include "weapons/melee_weapon.hpp"

class Ennemy : public Entity
{
public:
	// using Entity::Entity;
	Ennemy(sf::Vector2i pos);

	bool checkDamages(const MeleeWeapon& weapon);

private:
	bool invincibility;
	const float takenKnockback = 1;

	sf::Vector2f calculateKnockback(const MeleeWeapon& weapon);

};
