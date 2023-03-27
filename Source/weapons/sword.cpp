#include "weapons/sword.hpp"

Sword::Sword() {
		// rect.setTextureRect(sf::IntRect(0, 0, 8, 4));
		// damageHitbox.setTextureRect(sf::IntRect(0, 0, 6, 4));
		// TODO: rect is the texture
		damageHitbox.setScale(12, 8);
		damageHitboxRect.setSize(sf::Vector2f(12, 8));
		init();
}
