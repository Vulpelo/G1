#pragma once

#ifndef COLLISION_RECTANGLE_H
#define COLLISION_RECTANGLE_H

#include "Collision.h"
#include "SimpleShape.h"

namespace G1 {

	class CollisionRectangle : public Collision
	{
		double height, length;

	public:
		CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY, float rot = 0);
		bool isCollidingWith(Collision *otherCollider);
		Vector2 CollisionRectangle::getFarthestPointVector();
	};

}

#endif // COLLISION_RECTANGLE_H
