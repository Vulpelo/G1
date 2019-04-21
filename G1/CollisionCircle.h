#pragma once

#ifndef COLLISION_CIRCLE_H
#define COLLISION_CIRCLE_H

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class CollisionCircle : public Collider
	{
		double radius;

	public:
		CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY);
		bool isCollidingWith(Collider *otherCollider);
	};

}

#endif // !COLLISION_CIRCLE_H
