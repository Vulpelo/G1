#pragma once

#include "MapManager.h"

#include "Rigidbody.h"
#include "Collider.h"

namespace G1 {

	class RigidbodyPhysics
	{
		friend class PhysicsManager;
		friend class Collision;

		float gravity = 0.4f;

		RigidbodyPhysics() {};
		void applyForcesBeforeCollision() const;
		void calculateAndApplyForce(Rigidbody& rb1, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const;
		/// <summary>
		/// 
		/// </summary>
		float calculateCombineValue(float val1, float val2, Combine combine1) const;

		void applyForces(Rigidbody& rigidbody) const;
	};

}
