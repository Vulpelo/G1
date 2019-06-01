#pragma once

#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

#include "MapManager.h"
#include "OverlappingCheck.h"

#include "CircleOverlapsCircle.h"
#include "RectangleOverlapsRectangle.h"
#include "CircleOverlapsRectangle.h"
#include "CollisionCalculation.h"

namespace G1 {

	class CollisionDetection
	{
		CollisionCalculation collisionCallculation;

		std::vector<Overlapping*> collisionTypes;
		OverlappingCheck areColliding(Collider * collider1, Collider * collider2);
		void checkGameObjects(GameObject* gameObject1, GameObject* gameObject2);
	public:
		CollisionDetection();
		void checkCollisions();
		~CollisionDetection();
	};

}

#endif // !_COLLISION_DETECTION_H_
