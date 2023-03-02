#include "SFML/Graphics.hpp"
#include "player.hpp"
// #include "debuger.hpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	sf::RenderWindow window;
	sf::RenderTexture texture;

	Player player;

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
