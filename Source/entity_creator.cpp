#include "entity_creator.hpp"
#include <iostream>
#include <optional>

EntityCreator::EntityCreator(std::string fileName, float& _deltaTime) : deltaTime(_deltaTime) {
	tomlTable = toml::parse_file(fileName);
}

std::shared_ptr<Ennemy> EntityCreator::getEnemy(std::string name, sf::Vector2f pos) {
	
	float life = tomlTable["enemies"][name]["life"].value<float>().value(),
				strenght = tomlTable["enemies"][name]["strenght"].value<float>().value(),
				takenKnockback = tomlTable["enemies"][name]["takenKnockback"].value<float>().value(),
				width = tomlTable["enemies"][name]["width"].value<float>().value(),
				height = tomlTable["enemies"][name]["height"].value<float>().value();

	return std::make_shared<Ennemy>(pos, life, strenght, takenKnockback, width, height, deltaTime);

}

std::shared_ptr<MeleeWeapon> EntityCreator::getMeleeWeapon(std::string name) {

	float rotationSpeed = tomlTable["melee_weapons"][name]["rotationSpeed"].value<float>().value(),
				maxRotationForce = tomlTable["melee_weapons"][name]["maxRotationForce"].value<float>().value(),
				rotationMultiplicator = tomlTable["melee_weapons"][name]["rotationMultiplicator"]
					.value<float>().value(),
				damage = tomlTable["melee_weapons"][name]["damage"].value<float>().value(),
				knockback = tomlTable["melee_weapons"][name]["knockback"].value<float>().value(),
				width = tomlTable["melee_weapons"][name]["width"].value<float>().value(),
				height = tomlTable["melee_weapons"][name]["height"].value<float>().value();

	return std::make_shared<MeleeWeapon>(rotationSpeed, maxRotationForce, rotationSpeed, damage,
			knockback, sf::Vector2f(width, height), deltaTime);

}

std::shared_ptr<RangeWeapon> EntityCreator::getRangeWeapon(std::string name) {

	float range = tomlTable["range_weapons"][name]["range"].value<float>().value(),
				power = tomlTable["range_weapons"][name]["power"].value<float>().value(),
				percing = tomlTable["range_weapons"][name]["percing"].value<float>().value(),
				width = tomlTable["range_weapons"][name]["width"].value<float>().value(),
				height = tomlTable["range_weapons"][name]["height"].value<float>().value();

	return std::make_shared<RangeWeapon>(deltaTime, range, power, percing, sf::Vector2f(width, height));

}

std::shared_ptr<Projectile> EntityCreator::getProjectile(std::string name, RangeWeaponInfos info) {

	float damage = tomlTable["projectiles"][name]["damage"].value<float>().value(),
				range = tomlTable["projectiles"][name]["range"].value<float>().value(),
				speed = tomlTable["projectiles"][name]["speed"].value<float>().value(),
				width = tomlTable["projectiles"][name]["width"].value<float>().value(),
				height = tomlTable["projectiles"][name]["height"].value<float>().value();

	return std::make_shared<Projectile>(info, damage, range, speed, sf::Vector2f(width, height), deltaTime);

}
