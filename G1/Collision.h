#pragma once

#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "CollisionCheck.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "RigidbodyPhysics.h"
#include "GameObject.h"


namespace G1 {

	struct CollisionData {
		// When old velocity direction was rotated towards collider
		bool movingToCollider = true;
		Vector2 newVelocity;
	};

	class Collision
	{
		friend class CollisionCalculation;

		RigidbodyPhysics rigidbodyPhysics;

		virtual CollisionCheck calculate(Collider* collider1, Collider* collider2) = 0;
		virtual Vector2 calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2) = 0;

	protected:
		void applyNewVelocity(Rigidbody & rb1, const Collider& collider1, const Collider& collider2, const Vector2& velocity);
	};

}

#endif // !_COLLISION_H_
