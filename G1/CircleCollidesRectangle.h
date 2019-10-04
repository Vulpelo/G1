#pragma once

#ifndef CIRCLE_COLLIDES_RECTANGLE_H
#define CIRCLE_COLLIDES_RECTANGLE_H

#include "CircleCollidesCircle.h"
#include "RectangleCollidesRectangle.h"

namespace G1 {
	class CircleCollidesRectangle : public Collision
	{
		enum class VelocityFor {
			CIRCLE,
			RECTANGLE
		} velocityFor;

		RectangleCollidesRectangle rcr;
		CircleCollidesCircle cCc;

		Vector2 oneNewColliderPosition(Collider* dynamicCollider, Vector2 velocityDynamic, Collider * staticCollider);
		Vector2 calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2);
		RectangleCollider CircleCollidesRectangle::rectangleFromCircle(CircleCollider& circle);

	public:
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
	};
}

#endif // !CIRCLE_COLLIDES_RECTANGLE_H
