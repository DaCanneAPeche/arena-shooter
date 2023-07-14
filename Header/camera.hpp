#pragma once
#include "SFML/System/Vector2.hpp"

class Camera {

	public:
		// Camera();
		
		static constexpr float CAMERA_SPEED = 200;

		sf::Vector2f offset;
		void update(sf::Vector2f playerPosition, float deltaTime);

	private:
};
