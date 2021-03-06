#pragma once

#ifndef _CIRCLE_COLLIDES_CIRCLE_H_
#define _CIRCLE_COLLIDES_CIRCLE_H_

#include "Collision.h"
#include "CircleCollider.h"
#include "GameObject.h"
#include "Rigidbody.h"

namespace G1 { 
namespace PositionPerfect {

	class CircleCollidesCircle : public Collision
	{
		friend class CircleCollidesRectangle;

		Vector2 oneNewColliderPosition(Collider* circleColliderDynamic, const Vector2& velocityDynamic, Collider* circleColliderStatic);

	public:
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		void calculate(CircleCollider* circleColliderDynamic, Vector2 velocityDynamic, CircleCollider* circleColliderStatic);
		Vector2 calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2);
	};

}
namespace Resolution {
	class CircleCollidesCircle : public Collision
	{
		friend class CircleCollidesRectangle;

		Vector2 oneNewColliderPosition(Collider* circleColliderDynamic, const Vector2& velocityDynamic, Collider* circleColliderStatic);

	public:
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		Vector2 calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2);
	};
}
}

#endif //!_CIRCLE_COLLIDES_CIRCLE_H_
