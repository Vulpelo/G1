#include "RigidbodyPhysics.h"

namespace G1 {
	void RigidbodyPhysics::applyForcesBeforeCollision() const
	{
		auto gameObjects = MapManager::getInstance().get_aMap().getAllObjects();

		for each (GameObject* gObj in gameObjects)
		{
			auto rb = gObj->getComponent<Rigidbody>();
			if (rb) {
				applyForces(*rb);
			}
		}
	}

	Vector2 RigidbodyPhysics::calculateVelocity(Rigidbody& rb1, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const
	{
		const PhysicMaterial& pM1 = collider1.getPhysicMaterial();
		const PhysicMaterial& pM2 = collider2.getPhysicMaterial();

		return bounce((rb1.getVelocity().invert() + newVelocityDirection) / 2.0f, pM1, pM2)
			+ friction((rb1.getVelocity() + newVelocityDirection) / 2.f, pM1, pM2);
	}

	/// <summary>
	/// Calculate forces and apply new forces after Collision
	/// </summary>
	Vector2 RigidbodyPhysics::calculateVelocity(Rigidbody& rb1, const Rigidbody& rb2, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const
	{
		const PhysicMaterial& pM1 = collider1.getPhysicMaterial();
		const PhysicMaterial& pM2 = collider2.getPhysicMaterial();

		Vector2 bounceVec = (rb1.getVelocity().invert() + newVelocityDirection) / 2.0f;

		float m1 = rb1.getMass(), m2 = rb2.getMass();
		// if one of gameObjects have no mass (is static) then velocity wont change
		if (m1 != 0.f && m2 != 0.f) {
			Vector2 outVec = bounceVec.normalize();
			/* two dynamic colliders collided Collision */
			bounceVec = ( bounceVec * (m1 - m2) + 2*m2 * (rb2.getVelocity() * outVec * outVec) ) / (m1 + m2);
		}
 
		return bounce(bounceVec, pM1, pM2) 
			+ friction((rb1.getVelocity() + newVelocityDirection) / 2.f, pM1, pM2);
	}

	float RigidbodyPhysics::calculateCombineValue(float val1, float val2, Combine combine1) const {
		switch (combine1)
		{
		case Combine::MINIMUM:
			return val1 > val2 ? val2 : val1;
		case Combine::MAXIMUM:
			return val1 > val2 ? val1 : val2;
		case Combine::AVERAGE:
			return (val1 + val2) / 2.f;
		case Combine::MULTIPLY:
			return val1 * val2;
		default:
			return val1;
		}
	}

	void RigidbodyPhysics::applyForces(Rigidbody & rigidbody) const
	{
		/* Gravity */
		rigidbody.addForce (rigidbody.getGravity() * gravityMultiplier * Time::getDeltaTime());

		/* Drag */
		rigidbody.setVelocity ( rigidbody.getVelocity() - (rigidbody.getVelocity() * rigidbody.getDrag() * Time::getDeltaTime()) );
	}
	
	Vector2 RigidbodyPhysics::friction(const Vector2 & groundParaller, const PhysicMaterial & pM1, const PhysicMaterial & pM2) const
	{
		return groundParaller * (1.f - calculateCombineValue(pM1.friction, pM2.friction, pM1.frictionCombine));
		//(rb1.getVelocity() + newVelocityDirection) / 2.0f * (1.f - calculateCombineValue(pM1.friction, pM2.friction, pM1.frictionCombine));
		//float frictionLen = (frictionVec * newVelocityDirection);
		//frictionLen *= calculateCombineValue(pM1.friction, pM2.friction, pM1.frictionCombine);
	}
	Vector2 RigidbodyPhysics::bounce(const Vector2 & groundPerpendicular, const PhysicMaterial & pM1, const PhysicMaterial & pM2) const
	{
		return groundPerpendicular * calculateCombineValue(pM1.bounciness, pM2.bounciness, pM1.bouncyCombine);
		//		bounceVec *= calculateCombineValue(pM1.bounciness, pM2.bounciness, pM1.bouncyCombine);
		//float bounceLen = (bounceVec * newVelocityDirection);
		//bounceLen *= calculateCombineValue(pM1.bounciness, pM2.bounciness, pM1.bouncyCombine);
	}
}
