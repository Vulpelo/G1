#include "Collision.h"

namespace G1 {

	void Collision::startCalculating(Collider * collider1, Collider * collider2)
	{
		auto g1 = ((GameObject*)(collider1->getParent()));
		auto g2 = ((GameObject*)(collider2->getParent()));
		// TODO: world Velocity
		auto rb1 = g1->getComponent<Rigidbody>();
		auto rb2 = g2->getComponent<Rigidbody>();

		Transformable& topParent1 = collider1->getTopParent();
		Transformable& topParent2 = collider2->getTopParent();

		// TODO: Dynamic x Dynamic
		if (rb1 && rb2) {
			if (rb1->getVelocity().lengthNoSqrt() > rb2->getVelocity().lengthNoSqrt()) {
				topParent1.setPosition( oneNewColliderPosition(collider1, rb1->getVelocity(), collider2) );
			}
			else {
				topParent2.setPosition( oneNewColliderPosition(collider2, rb2->getVelocity(), collider1) );
			}

			Vector2 rb1NewVel = rigidbodyPhysics.calculateVelocity(*rb1, *rb2, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL));
			Vector2 rb2NewVel = rigidbodyPhysics.calculateVelocity(*rb2, *rb1, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL));

			rb1->setVelocity(rb1NewVel);
			rb2->setVelocity(rb2NewVel);

			return;
		}

		// Dynamic x Static
		if (rb1 && !rb2) {
			topParent1.setPosition( oneNewColliderPosition(collider1, rb1->getVelocity(), collider2) );

			rb1->setVelocity(rigidbodyPhysics.calculateVelocity(*rb1, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL)));
			return;
		}

		// Static x Dynamic
		if (!rb1 && rb2) {
			topParent2.setPosition( oneNewColliderPosition(collider2, rb2->getVelocity(), collider1) );
			
			rb2->setVelocity(rigidbodyPhysics.calculateVelocity(*rb2, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL)));
			return;
		}

	}

}
