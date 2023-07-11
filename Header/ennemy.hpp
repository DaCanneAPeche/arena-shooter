#pragma once

#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/projectile.hpp"
#include <memory>
#include <vector>
#include "timer.hpp"

class Ennemy : public Entity {
public:
	// using Entity::Entity;
	Ennemy(sf::Vector2f pos, float life, float _strenght, float _takenKnockback, float width,
			float height, float& _deltaTime);

	bool checkDamages(std::shared_ptr<MeleeWeapon> weapon, std::vector<std::shared_ptr<Projectile>> projectiles);
//	bool checkDamages(std::shared_ptr<RangeWeapon> weapon, std::vector<std::shared_ptr<BasicArrow>> projectiles);
	void moveToKb();

private:
	sf::Vector2f kb;
	float takenKnockback, strenght;

	float horizontalKb,
				verticalKb;

	sf::Vector2f calculateKnockback(const MeleeWeapon& weapon);

};
