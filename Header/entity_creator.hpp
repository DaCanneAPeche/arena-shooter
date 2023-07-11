#pragma once
#include "utils/toml/toml++/toml.h"
#include <string>
#include <memory>
#include "SFML/System/Vector2.hpp"

#include "ennemy.hpp"
#include "weapons/melee_weapon.hpp"
#include "weapons/range_weapon.hpp"
#include "weapons/projectile.hpp"
#include "weapons/range_weapon_info.hpp"

class EntityCreator {
	
	public:
		EntityCreator(std::string fileName, float& _deltaTime);

		std::shared_ptr<Ennemy> getEnemy(std::string name, sf::Vector2f pos);
		std::shared_ptr<MeleeWeapon> getMeleeWeapon(std::string name);
		std::shared_ptr<RangeWeapon> getRangeWeapon(std::string name);
		std::shared_ptr<Projectile> getProjectile(std::string name, RangeWeaponInfos info);

	private:

		toml::table tomlTable;
		float& deltaTime;

};
