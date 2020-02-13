#pragma once

#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

#include "MapManager.h"
#include "OverlappingCheck.h"

#include "CircleOverlapsCircle.h"
#include "RectangleOverlapsRectangle.h"
#include "CircleOverlapsRectangle.h"
#include "CollisionCalculation.h"

#include "PointOverlapsCircle.h"
#include "PointOverlapsRectangle.h"

namespace G1 {

	class CollisionDetection
	{
		friend class Physics;

		CollisionCalculation collisionCallculation;

		static std::vector<Overlapping*> collisionTypes;
		static std::vector<OverlapsPoint*> pointCollisionTypes;

		static OverlappingCheck areColliding(Collider * collider1, Collider * collider2);
		void checkGameObjects(GameObject* gameObject1, GameObject* gameObject2);

		static OverlappingCheck pointCollides(Collider * collider1, const Vector2& point);
		bool checkPointCollison(GameObject* gameObject, const Vector2& point);
	public:
		CollisionDetection();
		void checkCollisions();
	};

}

#endif // !_COLLISION_DETECTION_H_
