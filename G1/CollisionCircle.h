#pragma once

#ifndef COLLISION_CIRCLE_H
#define COLLISION_CIRCLE_H

#include "Collision.h"
#include "SimpleShape.h"

namespace G1 {

	class CollisionCircle : public Collision
	{
		double radius;

	public:
		CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY);
		bool isCollidingWith(Collision *otherCollider);
	};

}

#endif // !COLLISION_CIRCLE_H
