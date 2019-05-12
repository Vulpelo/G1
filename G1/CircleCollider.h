#pragma once

#ifndef _CIRCLE_COLLIDER_H_
#define _CIRCLE_COLLIDER_H_

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

#endif // !_CIRCLE_COLLIDER_H_
