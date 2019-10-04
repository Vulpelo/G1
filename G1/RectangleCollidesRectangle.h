#pragma once

#ifndef _RECTANGLE_COLLIDES_RECTANGLE_H
#define _RECTANGLE_COLLIDES_RECTANGLE_H

#include "Collision.h"
#include "CircleCollider.h"
#include "RectangleCollider.h"
#include "Segment.h"

namespace G1 {

	enum class SideOfRectangle {
		Undefined = -1,
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};

	class RectangleCollidesRectangle : public Collision {
		friend class CircleCollidesRectangle;

		SideOfRectangle sideOfRectangle;

		/// <summary>
		/// Calculates closest position for first collider so
		/// colliders aren't intersecting.
		/// </summary>
		/// <param name="collider1"></param>
		/// <param name="collider2"></param>
		/// <returns>New position for first collider</returns>
		Vector2 oneNewColliderPosition(RectangleCollider * rectangleColliderDynamic, Vector2 velocityDynamic, RectangleCollider * rectangleColliderStatic);

	public:
		RectangleCollidesRectangle() {};
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		Vector2 calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2);
		~RectangleCollidesRectangle();
	};

}

#endif // !_RECTANGLE_COLLIDES_RECTANGLE_H
