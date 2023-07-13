#include "npc.hpp"

Npc::Npc(sf::Vector2f pos, float& deltaTime) :
	sprite(sf::Vector2f(8, 8), pos, sf::Color::White, "NPCs", deltaTime) {}
