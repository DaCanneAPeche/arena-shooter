#pragma once

#include "SFML/System/Vector2.hpp"
#include "sprite.hpp"

class Npc {

public:
	Npc(sf::Vector2f pos, float& _deltaTime);
	Sprite sprite;

private:
	
};
