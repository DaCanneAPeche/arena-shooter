#include "SFML/Graphics.hpp"
#include <vector>
#include "player.hpp"
#include "ennemy.hpp"
// #include "debuger.hpp"
#include <memory>

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

public:
	Game();
	int run();
};

#endif /* GAME_H */
