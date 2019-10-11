#include "RigidbodyPhysics.h"

namespace G1 {
	void RigidbodyPhysics::applyForcesBeforeCollision() const
	{
		auto gameObjects = MapManager::get_aMap()->getAllObjects();

		for each (GameObject* gObj in gameObjects)
		{
			auto rb = gObj->getComponent<Rigidbody>();
			if (rb) {
				applyForces(*rb);
			}
		}
	}

	/// <summary>
	/// Calculate forces and apply new forces after Collision
	/// </summary>
	void RigidbodyPhysics::calculateAndApplyForce(Rigidbody& rb1, const Collider& collider1, const Collider& collider2, const Vector2& newVelocityDirection) const
	{
		const PhysicMaterial& pM1 = collider1.getPhysicMaterial();
		const PhysicMaterial& pM2 = collider2.getPhysicMaterial();


		/* Bounce */ 
		Vector2 bounceVec = (rb1.getVelocity().invert() + newVelocityDirection) / 2.0f * calculateCombineValue(pM1.bounciness, pM2.bounciness, pM1.bouncyCombine);
		//float bounceLen = (bounceVec * newVelocityDirection);
		//bounceLen *= calculateCombineValue(pM1.bounciness, pM2.bounciness, pM1.bouncyCombine);

		/* Friction */
		Vector2 frictionVec = (rb1.getVelocity() + newVelocityDirection) / 2.0f * (1.f - calculateCombineValue(pM1.friction, pM2.friction, pM1.frictionCombine));
		//float frictionLen = (frictionVec * newVelocityDirection);
		//frictionLen *= calculateCombineValue(pM1.friction, pM2.friction, pM1.frictionCombine);

		rb1.setVelocity(bounceVec + frictionVec);
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
		rigidbody.addForce(Vector2::down() * gravity);

		/* Drag */
		rigidbody.setVelocity (rigidbody.getVelocity() - rigidbody.getVelocity() * rigidbody.getDrag());
	}
}
