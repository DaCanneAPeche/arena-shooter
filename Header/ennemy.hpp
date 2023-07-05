#pragma once

#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/basic_arrow.hpp"
#include <memory>
#include <vector>
#include "timer.hpp"

class Ennemy : public Entity
{
public:
	// using Entity::Entity;
	Ennemy(sf::Vector2f pos, float& _deltaTime);

	bool checkDamages(const MeleeWeapon& weapon, std::vector<std::shared_ptr<BasicArrow>> projectiles);
	void moveToKb();

private:
	sf::Vector2f kb;
	const float takenKnockback = 1;

	float horizontalKb,
				verticalKb;

	sf::Vector2f calculateKnockback(const MeleeWeapon& weapon);

};
