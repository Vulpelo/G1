#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "MathFunctions.h"
#include "Component.h"

namespace G1 {

	class Collider : public Component
	{
	protected:
		char collisionType;
		float farthestPoint;
		float nearestPoint;
		//not actually used
		void draw(sf::RenderWindow * w);
		bool rectangleOverlapsCircle(Collider*rect, Collider*cirl);
		bool rectangleOverlapsRectangle(Collider*rect, Collider*otherRect);
		bool rectangleOverlapsPoint(Position point);

	public:
		Collider();
		char getCollisionType();
		virtual bool isCollidingWith(Collider *otherCollider) = 0;

		virtual Vector2 getFarthestPointVector();
		// returns distance from origin of colider to the farthest point on the colider
		float getFarthestPoint();
		// returns distance from origin of colider to the nearest point on the colider
		float getNearestPoint();
	};

}

#endif // !COLLISION_H