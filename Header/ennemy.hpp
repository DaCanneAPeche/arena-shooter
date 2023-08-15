#pragma once

#include "entity.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/projectile.hpp"
#include <memory>
#include <vector>
#include <string>
#include "timer.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "utils/rng.hpp"

namespace behaviors {
	const short patrolling = 0;
	const short attackingNpc = 1;
	const short attackingPlayer = 2;
}

class Ennemy : public Entity {
public:
	// using Entity::Entity;
	Ennemy(sf::Vector2f pos, float life, float _strenght, float _takenKnockback, float width,
			float height, std::string assetName, 
			std::vector<std::shared_ptr<Ennemy>>& _enemies, std::vector<std::shared_ptr<Npc>>& _npcs, 
			const Player& _player, float& _deltaTime);

	bool checkDamages(std::shared_ptr<MeleeWeapon> weapon, std::vector<std::shared_ptr<Projectile>> projectiles);
	void behave();
	//	bool checkDamages(std::shared_ptr<RangeWeapon> weapon, std::vector<std::shared_ptr<BasicArrow>> projectiles);
	void moveToKb();
	void playerFound();

private:
	const float vision = 10;
	const float speed = 80;
	const float VOICE = 100;

	sf::Vector2f kb;
	float takenKnockback, strenght;

	float horizontalKb,
				verticalKb;

	const Player& player;
	std::vector<std::shared_ptr<Ennemy>>& enemies;
	std::vector<std::shared_ptr<Npc>>& npcs;

	short state;

	sf::Vector2f calculateKnockback(const MeleeWeapon& weapon);

	const Sprite& getClosestSprite();
	float getDistance(sf::Vector2f pos);
	bool isClosestSpriteAnNpc;
	std::shared_ptr<Sprite> closestSprite;
	bool moveToPos(sf::Vector2f pos);
	sf::Vector2f nextPos;
	Rng rng;

};
