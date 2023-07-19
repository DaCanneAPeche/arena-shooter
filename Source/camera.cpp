#include "camera.hpp"
#include <iostream>

void Camera::update(sf::Vector2f playerPosition, float deltaTime) {
	offset.x = playerPosition.x - 121;
	offset.y = playerPosition.y - 121;
	
	/*if (offset.x < playerPosition.x - 121 && offset.x + CAMERA_SPEED * deltaTime < playerPosition.x - 121)
		offset.x += CAMERA_SPEED * deltaTime;
	else if (offset.x > playerPosition.x - 121 && offset.x - CAMERA_SPEED * deltaTime > playerPosition.x - 121)
		offset.x -= CAMERA_SPEED * deltaTime;

	if (offset.y < playerPosition.y - 121 && offset.y + CAMERA_SPEED * deltaTime < playerPosition.y - 121)
		offset.y += CAMERA_SPEED * deltaTime;
	else if (offset.y > playerPosition.y - 121 && offset.y - CAMERA_SPEED * deltaTime > playerPosition.y - 121)
		offset.y -= CAMERA_SPEED * deltaTime;
*/
}
