#pragma once

#include "MapManager.h"

#include "Rigidbody.h"
#include "Collider.h"

namespace G1 {

	class RigidbodyPhysics
	{
		friend class PhysicsManager;
		friend class Collision;

		float gravityMultiplier = 1.f;

		RigidbodyPhysics() {};
		void applyForcesBeforeCollision() const;
		
		Vector2 calculateVelocity(Rigidbody& rb1, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const;
		Vector2 calculateVelocity(Rigidbody& rb1, const Rigidbody& rb2, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const;
		/// <summary>
		/// 
		/// </summary>
		float calculateCombineValue(float val1, float val2, Combine combine1) const;

		void applyForces(Rigidbody& rigidbody) const;

		Vector2 friction(const Vector2 & groundParaller, const PhysicMaterial & pM1, const PhysicMaterial & pM2) const;
		Vector2 bounce(const Vector2 & groundPerpendicular, const PhysicMaterial & pM1, const PhysicMaterial & pM2) const;
	};

}
