#include "ennemy.hpp"
#include "../Tools/collision.hpp"
#include "weapons/melee_weapon.hpp"
#include <iostream>
#include <utility>
#include <cmath>

Ennemy::Ennemy(sf::Vector2i pos) : Entity(pos, sf::Vector2i(8, 8), sf::Color::Red, 400) {
	invincibility = false;
}

bool Ennemy::checkDamages(const MeleeWeapon& weapon) {

	// MeleeWeapon m_weapon = std::move(weapon);
	sf::Vector2f mtv;
	
	if (testCollision(r, weapon.damageHitboxRect, mtv) && !invincibility) {
		invincibility = true;
		damage(weapon.damage * weapon.rotationForce);
		std::cout << "Collisions !" << std::endl;

		sf::Vector2f kb = calculateKnockback(weapon);
		std::cout << kb.x << ' ' << kb.y << std::endl;

		move(kb.x, kb.y, 1);
	}

	return false;
}

sf::Vector2f Ennemy::calculateKnockback(const MeleeWeapon& weapon) {
	sf::Vector2f kb;
	float kbAmount = weapon.knockback * weapon.rotationForce * takenKnockback;
	float x = rect.left / 4 - weapon.entityPos.x / 4,
				y = rect.top / 4 - weapon.entityPos.y / 4;
	float hypotenuse = std::sqrt(x * x + y * y);
	std::cout << hypotenuse << std::endl;
	std::cout << x << " &&&& " << y << std::endl;

	kb.x = kbAmount * x / hypotenuse;
	kb.y = kbAmount * y / hypotenuse;

	return kb;
}
