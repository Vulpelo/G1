#pragma once

#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include "MathFunctions.h"
#include "Component.h"

namespace G1 {

	class Collider : public Component, public Transformable
	{
		bool overlappable;

	protected:
		char collisionType;
		float farthestPoint;
		float nearestPoint;
		//not actually used
		void draw(sf::RenderWindow * w);
		bool rectangleOverlapsCircle(Collider*rect, Collider*cirl);
		bool rectangleOverlapsRectangle(Collider*rect, Collider*otherRect);
		bool rectangleOverlapsPoint(Vector2 point);

	public:
		Collider();
		char getCollisionType();
		virtual bool isCollidingWith(Collider *otherCollider) = 0;

		bool isOverlappable();
		void setOverlappable(bool overlappable);

		virtual Vector2 getFarthestPointVector();
		// returns distance from origin of colider to the farthest point on the colider
		float getFarthestPoint();
		// returns distance from origin of colider to the nearest point on the colider
		float getNearestPoint();
	};

}

#endif // !_COLLIDER_H_
