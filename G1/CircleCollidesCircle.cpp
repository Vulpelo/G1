#include "CircleCollidesCircle.h"

namespace G1 {
	namespace PositionPerfect {
		Vector2 CircleCollidesCircle::oneNewColliderPosition(Collider * circleColliderDynamic, const Vector2 & velocityDynamic, Collider * circleColliderStatic)
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

			Vector2 po = (S1 - circleColliderDynamic->getWorldPosition()) + topParentPosition;
			//std::cout << po.x << ":" << po.y << std::endl;
			return (S1 - circleColliderDynamic->getWorldPosition()) + topParentPosition;
		}

		CollisionCheck CircleCollidesCircle::calculate(Collider * collider1, Collider * collider2)
		{
			if (dynamic_cast<CircleCollider*>(collider1)
				&& dynamic_cast<CircleCollider*>(collider2))
			{
				startCalculating(collider1, collider2);
				return CollisionCheck::CALCULATED;
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

	}

	namespace Resolution {
		Vector2 CircleCollidesCircle::oneNewColliderPosition(Collider * circleColliderDynamic, const Vector2 & velocityDynamic, Collider * circleColliderStatic)
		{
			Vector2 dynPosition = circleColliderDynamic->getWorldPosition();
			Vector2 statPosition = circleColliderStatic->getWorldPosition();

			Vector2 outDir = (dynPosition - statPosition).normalize();

			float penetration = (circleColliderDynamic->getFarthestPoint() + circleColliderStatic->getFarthestPoint()) - 
								(dynPosition - statPosition).length();

			return dynPosition + outDir * penetration;
		}

		CollisionCheck CircleCollidesCircle::calculate(Collider * collider1, Collider * collider2)
		{
			if (dynamic_cast<CircleCollider*>(collider1)
				&& dynamic_cast<CircleCollider*>(collider2))
			{
				startCalculating(collider1, collider2);
				return CollisionCheck::CALCULATED;
			}
			return CollisionCheck::ERROR_TYPE;
		}

		Vector2 CircleCollidesCircle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
		{
			Vector2 Vsoj = (gameObject1->getWorldPosition() - gameObject2->getWorldPosition()).normalize();
			Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
			return rigidbody1->getVelocity() - (Vso * 2);
		}
	}
}