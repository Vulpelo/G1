#include "CircleCollidesCircle.h"

namespace G1 {

	CircleCollidesCircle::CircleCollidesCircle()
	{
	}

	CollisionCheck CircleCollidesCircle::calculate(Collider * collider1, Collider * collider2)
	{
		CircleCollider* circle1 = dynamic_cast<CircleCollider*>(collider1);
		CircleCollider* circle2 = dynamic_cast<CircleCollider*>(collider2);

		if (circle1 && circle2) {
			auto g1 = ((GameObject*)(circle1->getParent()));
			auto g2 = ((GameObject*)circle2->getParent());
			// TODO: world Velocity
			auto rb1 = g1->getComponent<Rigidbody>();
			auto rb2 = g2->getComponent<Rigidbody>();
			
			// Dynamic x Dynamic
			if (rb1 && rb2) {
				cirDynCirDyn.calculate(circle1, rb1->getVelocity(), circle2, rb2->getVelocity());
				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) { 
				cirDynCirStat.calculate(circle1, rb1->getVelocity(), circle2);
				calculateVelocityDirection(g1, rb1, g2, NULL);
				return CollisionCheck::CALCULATED;
			}// Static x Dynamic
			else if (!rb1 && rb2) {
				cirDynCirStat.calculate(circle2, rb2->getVelocity(), circle1);
				calculateVelocityDirection(g2, rb2, g1, NULL);
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	void CircleCollidesCircle::
		calculate(CircleCollider * circleColliderDynamic, Vector2 velocityDynamic, CircleCollider * circleColliderStatic)
	{
	}

	void CircleCollidesCircle::calculateVelocityDirection(GameObject * gameObject1, Rigidbody * rigidbody1, GameObject * gameObject2, Rigidbody * rigidbody2)
	{
		Vector2 Vsoj = (gameObject1->getWorldPosition() - gameObject2->getWorldPosition()).normalize();
		Vector2 Vso = Vsoj * (rigidbody1->getVelocity() * Vsoj);
		rigidbody1->setVelocity(rigidbody1->getVelocity() - (Vso * 2));
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
