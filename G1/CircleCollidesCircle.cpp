#include "CircleCollidesCircle.h"

namespace G1 {
	Vector2 CircleCollidesCircle::oneNewColliderPosition(CircleCollider * circleColliderDynamic, const Vector2 & velocityDynamic, CircleCollider * circleColliderStatic)
	{
		// there can be only one collider in gameobject tree hierarchy. Only First gameObect (with paret=null) can have collider
		// collider cant have offset.
		// get worldPosition of circleColliderDynamic as position
		Vector2 topParentPosition = circleColliderDynamic->getTopParent().getWorldPosition();

		Vector2 V1j = velocityDynamic.normalize(); // creating unitary vector

												   // distance between centero of dynamic collider and cross point of straight perpendicular going thru center of static collider
												   // to velocity vector
		float h = V1j * (circleColliderDynamic->getWorldPosition() - circleColliderStatic->getWorldPosition());

		Vector2 hv = V1j * h;

		Vector2 G1 = circleColliderDynamic->getWorldPosition() - hv;

		float d = circleColliderDynamic->getFarthestPoint() + circleColliderStatic->getFarthestPoint();

		float hh = (G1 - circleColliderStatic->getWorldPosition()).length();

		float b = d*d - hh*hh;
		float x = sqrtf(fabsf(b));

		Vector2 S1 = (V1j * x - G1) * (-1);

		float rest = (circleColliderDynamic->getWorldPosition() - velocityDynamic - S1).length();

		return (S1 - circleColliderDynamic->getWorldPosition()) + topParentPosition;
	}

	CircleCollidesCircle::CircleCollidesCircle()
	{

	}

	CollisionCheck CircleCollidesCircle::calculate(Collider * collider1, Collider * collider2)
	{
		CircleCollider* circle1 = dynamic_cast<CircleCollider*>(collider1);
		CircleCollider* circle2 = dynamic_cast<CircleCollider*>(collider2);

		if (circle1 && circle2) {
			auto g1 = ((GameObject*)(circle1->getParent()));
			auto g2 = ((GameObject*)(circle2->getParent()));
			// TODO: world Velocity
			auto rb1 = g1->getComponent<Rigidbody>();
			auto rb2 = g2->getComponent<Rigidbody>();
			
			Transformable& topParentCircle1 = circle1->getTopParent();
			Transformable& topParentCircle2 = circle2->getTopParent();

			// TODO: Dynamic x Dynamic
			if (rb1 && rb2) {

				topParentCircle1.setPosition(
					oneNewColliderPosition(circle1, rb1->getVelocity(), circle2)
				);

				applyNewVelocity(*rb1, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL));
				applyNewVelocity(*rb2, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL));

				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) { 

				topParentCircle1.setPosition(
					oneNewColliderPosition(circle1, rb1->getVelocity(), circle2)
				);
				applyNewVelocity(*rb1, *collider1, *collider2, calculateVelocityDirection(g1, rb1, g2, NULL));
				return CollisionCheck::CALCULATED;
			}
			// Static x Dynamic
			else if (!rb1 && rb2) {

				topParentCircle2.setPosition(
					oneNewColliderPosition(circle2, rb2->getVelocity(), circle1)
				);

				applyNewVelocity(*rb2, *collider2, *collider1, calculateVelocityDirection(g2, rb2, g1, NULL));
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	void CircleCollidesCircle::
		calculate(CircleCollider * circleColliderDynamic, Vector2 velocityDynamic, CircleCollider * circleColliderStatic)
	{
	}

	Vector2 CircleCollidesCircle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
	{
		Vector2 Vsoj = (gameObject1->getWorldPosition() - gameObject2->getWorldPosition()).normalize();
		Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
		return rigidbody1->getVelocity() - (Vso * 2);
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
