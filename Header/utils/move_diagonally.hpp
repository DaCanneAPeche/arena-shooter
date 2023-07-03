#pragma once
#include "SFML/System/Vector2.hpp"
#include "sprite.hpp"

sf::Vector2f moveDiagonally(float amount, sf::Vector2f source, Sprite sprite);
sf::Vector2f moveDiagonallyByAngle(float amount, float angle, Sprite sprite);
