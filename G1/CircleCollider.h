#pragma once

#ifndef COLLISION_CIRCLE_H
#define COLLISION_CIRCLE_H

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class CircleCollider : public Collider
	{
		double radius;

	public:
		CircleCollider(float radius, float worldCoordinateX, float worldCoordinateY);
		bool isCollidingWith(Collider *otherCollider);
	};

}

#endif // !COLLISION_CIRCLE_H
