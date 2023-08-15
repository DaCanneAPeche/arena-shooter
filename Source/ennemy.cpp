#include "ennemy.hpp"
#include "utils/collision.hpp"
#include "weapons/melee_weapon.hpp"
#include <iostream>
#include <utility>
#include "utils/move_diagonally.hpp"
#include <cmath>


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

	state = behaviors::patrolling;

}

bool Ennemy::checkDamages(std::shared_ptr<MeleeWeapon> weapon, std::vector<std::shared_ptr<Projectile>> projectiles) {

	// MeleeWeapon m_weapon = std::move(weapon);
	if (!invincibility) {
	
		if (sprite.collide(weapon->sprite)) {
			damage(weapon->damage * weapon->rotationForce);

			// kb = calculateKnockback(weapon);
			kb = moveDiagonallyByAngle(weapon->knockback * weapon->rotationForce * takenKnockback,
					weapon->rotation, sprite);

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

	float kbMultiplicator = 12;
	move(horizontalKb * kbMultiplicator, verticalKb * kbMultiplicator);
	horizontalKb -= horizontalKb * deltaTime * kbMultiplicator;
	verticalKb -= verticalKb * deltaTime * kbMultiplicator;

}

// AI
void Ennemy::behave() {
	switch (state) {
		case (behaviors::patrolling):

			if (nextPos == sf::Vector2f(0, 0)) nextPos = sprite.pos;

			if (moveToPos(nextPos)) {
				int direction = rng(0, 3);
				int distance = rng(40, 100);

				switch (direction) {
					case 0: nextPos = sf::Vector2f(sprite.pos.x + distance, sprite.pos.y); break;
					case 1: nextPos = sf::Vector2f(sprite.pos.x - distance, sprite.pos.y); break;
					case 2: nextPos = sf::Vector2f(sprite.pos.x, sprite.pos.y + distance); break;
					case 3: nextPos = sf::Vector2f(sprite.pos.x, sprite.pos.y - distance); break;
						
				}

			}
			
			closestSprite = std::make_shared<Sprite>(getClosestSprite());

			if (getDistance(closestSprite->pos) > vision) break;

			if (isClosestSpriteAnNpc) {
				state = behaviors::attackingNpc;
			} else state = behaviors::attackingPlayer;

			break;

		case (behaviors::attackingNpc):

			closestSprite = std::make_shared<Sprite>(getClosestSprite());

			if (getDistance(closestSprite->pos) > vision) {state = behaviors::patrolling; break;}
			std::cout << "azertyui" << std::endl;
			if (!isClosestSpriteAnNpc) state = behaviors::attackingPlayer;

			if (verticalKb && horizontalKb) break;
			if (moveToPos(closestSprite->pos)) {
				for (const auto& npc : npcs) {
					if (npc->sprite.pos == closestSprite->pos)
						npcs.erase(std::remove(npcs.begin(), npcs.end(), npc), npcs.end());
						break;
				}
			}

			break;

		case (behaviors::attackingPlayer):

			if (!verticalKb && !horizontalKb)
				moveToPos(player.sprite.pos);

	}
}

const Sprite& Ennemy::getClosestSprite() {
	std::vector<Sprite> sprites;
	float shortestDistance = getDistance(player.sprite.pos);
	sf::Vector2f closestPos = player.sprite.pos;
	sprites.push_back(player.sprite);

	isClosestSpriteAnNpc = false;

	for (const auto& npc : npcs ) {
		sprites.push_back(npc->sprite);
		float d = getDistance(npc->sprite.pos);

		if (d < shortestDistance) {
			shortestDistance = d;
			closestPos = npc->sprite.pos;
			isClosestSpriteAnNpc = true;
		}
	}

	for (const auto& sprite : sprites) {
		if (sprite.pos == closestPos) {
			return sprite;
		}
	}

	return player.sprite;
}

float Ennemy::getDistance(sf::Vector2f pos) {
	float x = sprite.pos.x - pos.x,
				y = sprite.pos.y - pos.y;
	return std::sqrt(x * x + y * y);
}

bool Ennemy::moveToPos(sf::Vector2f pos) {
	float x = 0, y = 0;

	if (sprite.pos.x > pos.x && (sprite.pos.x - deltaTime * speed > pos.x)) x = -1 * speed;
	else if (sprite.pos.x < pos.x && (sprite.pos.x + deltaTime * speed < pos.x)) x = speed;

	if (sprite.pos.y > pos.y && (sprite.pos.y - deltaTime * speed > pos.y)) y = -1 * speed;
	else if (sprite.pos.y < pos.y && (sprite.pos.y + deltaTime * speed < pos.y)) y = speed;

	if (x || y) {
		move(x, y);
		return false;
	}
	else return true;

}
