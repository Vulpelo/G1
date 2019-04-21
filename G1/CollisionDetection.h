#pragma once

#include "MapManager.h"
#include "CollisionCheck.h"

#include "CircleCollidesCircle.h"
#include "RectangleCollidesRectangle.h"
#include "CircleCollidesRectangle.h"

namespace G1 {

	class CollisionDetection
	{
		std::vector<Collision*> collisionTypes;
		CollisionCheck areColliding(Collider * collider1, Collider * collider2);
		void checkGameObjects(GameObject* gameObject1, GameObject* gameObject2);
	public:
		CollisionDetection();
		void checkCollisions();
		~CollisionDetection();
	};

}
