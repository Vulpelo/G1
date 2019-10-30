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

		/// <summary>
		/// Calculates everything on collision
		/// </summary>
		/// <returns></returns>
		virtual CollisionCheck calculate(Collider* collider1, Collider* collider2) = 0;
		
		/// <summary>
		/// Calculates new velocity direction when collided
		/// </summary>
		virtual Vector2 calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2) = 0;

		//void staticXDynamic(GameObject& g1, GameObject& g2, Collider * collider1, Collider * collider2);
		//void dynamicXDynamic(GameObject& g1, GameObject& g2, Collider * collider1, Collider * collider2);

		virtual Vector2 oneNewColliderPosition(Collider * rectangleColliderDynamic, const Vector2& velocityDynamic, Collider* rectangleColliderStatic) = 0;

	protected:
		void startCalculating(Collider * collider1, Collider * collider2);
	};

}

#endif // !_COLLISION_H_
