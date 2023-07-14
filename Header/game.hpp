#include "SFML/Graphics.hpp"
#include <vector>
#include "player.hpp"
#include "ennemy.hpp"
#include "weapons/melee_weapon.hpp"
#include "timer.hpp"
#include "npc.hpp"
// #include "debuger.hpp"
#include <memory>
#include "entity_creator.hpp"
#include "camera.hpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	sf::RenderWindow window;
	sf::RenderTexture texture;

	Player player;

	std::vector<std::shared_ptr<Ennemy>> ennemies;

	sf::Clock dtClock;
	float deltaTime;

	void handleEvents();
	void update();
	void render();

	std::vector<std::shared_ptr<Npc>> npcs;

	EntityCreator entityCreator;
	Camera camera;

public:
	Game();
	int run();
};

#endif /* GAME_H */
