#pragma once

#ifndef COLLISION_RECTANGLE_H
#define COLLISION_RECTANGLE_H

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class CollisionRectangle : public Collider
	{
		double height, length;

	public:
		CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY, float rot = 0);
		bool isCollidingWith(Collider *otherCollider);
		Vector2 CollisionRectangle::getFarthestPointVector();
	};

}

#endif // COLLISION_RECTANGLE_H
