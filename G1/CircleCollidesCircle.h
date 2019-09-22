#pragma once

#ifndef _CIRCLE_COLLIDES_CIRCLE_H_
#define _CIRCLE_COLLIDES_CIRCLE_H_

#include "Collision.h"
#include "CircleCollider.h"
#include "GameObject.h"
#include "Rigidbody.h"

namespace G1 {

	class CircleCollidesCircle : public Collision
	{
		friend class CircleCollidesRectangle;

		Vector2 oneNewColliderPosition(CircleCollider* circleColliderDynamic, const Vector2& velocityDynamic, CircleCollider* circleColliderStatic);

	public:
		CircleCollidesCircle();
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		void calculate(CircleCollider* circleColliderDynamic, Vector2 velocityDynamic, CircleCollider* circleColliderStatic);
		void calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2);
		~CircleCollidesCircle();
	};

}

#endif //!_CIRCLE_COLLIDES_CIRCLE_H_
