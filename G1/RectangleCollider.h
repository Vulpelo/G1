#pragma once

#ifndef COLLISION_RECTANGLE_H
#define COLLISION_RECTANGLE_H

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class RectangleCollider : public Collider
	{
		float height, length;

	public:
		RectangleCollider(float length, float height, float worldCoordinateX, float worldCoordinateY, float rot = 0);
		bool isCollidingWith(Collider *otherCollider);
		Vector2 RectangleCollider::getFarthestPointVector();
	};

}

#endif // COLLISION_RECTANGLE_H
