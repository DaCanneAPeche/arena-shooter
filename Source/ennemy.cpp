#include "ennemy.hpp"
#include "utils/collision.hpp"
#include "weapons/melee_weapon.hpp"
#include <iostream>
#include <utility>
#include "utils/move_diagonally.hpp"


Ennemy::Ennemy(sf::Vector2f pos, float life, float _strenght, float _takenKnockback, float width,
			float height, std::string assetName, std::vector<std::shared_ptr<Ennemy>>& _enemies,
			std::vector<std::shared_ptr<Npc>>& _npcs, const Player& _player, float& _deltaTime) : 
	Entity(pos, sf::Vector2f(width, height), sf::Color::Red, life, assetName, _deltaTime), player(_player),
	npcs(_npcs), enemies(_enemies) {

	invincibility = false;
	verticalKb = 0;
	horizontalKb = 0;

	takenKnockback = _takenKnockback;
	strenght = _strenght;

}

bool Ennemy::checkDamages(std::shared_ptr<MeleeWeapon> weapon, std::vector<std::shared_ptr<Projectile>> projectiles) {

	// MeleeWeapon m_weapon = std::move(weapon);
	if (!invincibility) {
	
		if (sprite.collide(weapon->sprite)) {
			damage(weapon->damage * weapon->rotationForce);

			// kb = calculateKnockback(weapon);
			kb = moveDiagonally(weapon->knockback * weapon->rotationForce * takenKnockback,
					weapon->entityPos, sprite);

			horizontalKb = kb.x;
			verticalKb = kb.y;

			// move(kb.x, kb.y);
			// std::cout << deltaTime << std::endl;
		}

		for (const auto& projectile : projectiles) {
			if (sprite.collide(projectile.get()->sprite)) {

				kb = moveDiagonally(damage(projectile->weaponInfo.power * projectile->damage) / 10 * takenKnockback,
						projectile->weaponInfo.entityPos, sprite);

				horizontalKb = kb.x;
				verticalKb = kb.y;
				projectile->percing--;

				break;
			}
		}
		 
	}

	if (timer.checkTime(false)) invincibility = false;

	return false;
}

/* sf::Vector2f Ennemy::calculateKnockback(const MeleeWeapon& weapon) {
	sf::Vector2f _kb;
	float kbAmount = weapon.knockback * weapon.rotationForce * takenKnockback;
	float x = sprite.pos.x / 4 - weapon.entityPos.x / 4,
				y = sprite.pos.y / 4 - weapon.entityPos.y / 4;
	float hypotenuse = std::sqrt(x * x + y * y);

	_kb.x = kbAmount * x / hypotenuse;
	_kb.y = kbAmount * y / hypotenuse;

	return _kb;
}*/

void Ennemy::moveToKb() {

	if (verticalKb < 0.1 && verticalKb > -0.1) verticalKb = 0;
	if (horizontalKb < 0.1 && horizontalKb > -0.1) horizontalKb = 0;

	float kbMultiplicator = 8;
	move(horizontalKb * kbMultiplicator, verticalKb * kbMultiplicator);
	horizontalKb -= horizontalKb * deltaTime * kbMultiplicator;
	verticalKb -= verticalKb * deltaTime * kbMultiplicator;

}

