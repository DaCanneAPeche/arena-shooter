#include "ennemy.hpp"
#include "../Tools/collision.hpp"
#include "weapons/melee_weapon.hpp"
#include <iostream>
#include <utility>

Ennemy::Ennemy(sf::Vector2i pos) : Entity(pos, sf::Vector2i(8, 8), sf::Color::Red, 400) {
	invincibility = false;
}

bool Ennemy::checkDamages(const MeleeWeapon& weapon) {

	// MeleeWeapon m_weapon = std::move(weapon);
	sf::Vector2f mtv;
	
	if (testCollision(r, weapon.damageHitboxRect, mtv) && !invincibility) {
		invincibility = true;
		damage(weapon.damage * weapon.rotationForce);
		std::cout << weapon.damage * weapon.rotationForce << std::endl;
		std::cout << "Collisions !" << std::endl;
	}

	return false;
}
