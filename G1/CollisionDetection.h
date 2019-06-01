#pragma once

#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

#include "MapManager.h"
#include "CollisionCheck.h"

#include "CircleOverlapsCircle.h"
#include "RectangleOverlapsRectangle.h"
#include "CircleOverlapsRectangle.h"

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

#endif // !_COLLISION_DETECTION_H_
