#include "ennemy.hpp"
#include "../Tools/collision.hpp"
#include "weapons/melee_weapon.hpp"
#include <iostream>
#include <utility>
#include <cmath>


Ennemy::Ennemy(sf::Vector2f pos, float& _deltaTime) : 
	Entity(pos, sf::Vector2f(8, 8), sf::Color::Red, 4000, _deltaTime) {
	invincibility = false;
	verticalKb = 0;
	horizontalKb = 0;
}

bool Ennemy::checkDamages(const MeleeWeapon& weapon) {

	// MeleeWeapon m_weapon = std::move(weapon);
	
	if (sprite.collide(weapon.sprite) && !invincibility) {
		invincibility = true;
		timer.setTimer(1);
		damage(weapon.damage * weapon.rotationForce);

		kb = calculateKnockback(weapon);

		horizontalKb = kb.x;
		verticalKb = kb.y;

		// move(kb.x, kb.y);
		// std::cout << deltaTime << std::endl;
	}

	if (timer.checkTime(false)) invincibility = false;

	return false;
}

sf::Vector2f Ennemy::calculateKnockback(const MeleeWeapon& weapon) {
	sf::Vector2f _kb;
	float kbAmount = weapon.knockback * weapon.rotationForce * takenKnockback;
	float x = sprite.pos.x / 4 - weapon.entityPos.x / 4,
				y = sprite.pos.y / 4 - weapon.entityPos.y / 4;
	float hypotenuse = std::sqrt(x * x + y * y);

	_kb.x = kbAmount * x / hypotenuse;
	_kb.y = kbAmount * y / hypotenuse;

	return _kb;
}

void Ennemy::moveToKb() {

	if (verticalKb < 0.1 && verticalKb > -0.1) verticalKb = 0;
	if (horizontalKb < 0.1 && horizontalKb > -0.1) horizontalKb = 0;

	float kbMultiplicator = 8;
	move(horizontalKb * kbMultiplicator, verticalKb * kbMultiplicator);
	horizontalKb -= horizontalKb * deltaTime * kbMultiplicator;
	verticalKb -= verticalKb * deltaTime * kbMultiplicator;

}

