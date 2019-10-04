#include "Collision.h"

namespace G1 {



	void Collision::applyNewVelocity(Rigidbody & rb1, const Collider& collider1, const Collider& collider2, const Vector2& velocity)
	{
		rigidbodyPhysics.calculateAndApplyForce(rb1, collider1, collider2, velocity);
	}

}
