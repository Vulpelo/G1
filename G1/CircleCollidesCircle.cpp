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
			
			if (rb1 && rb2) {
				cirDynCirDyn.calculate(circle1, rb1->getVelocity(), circle2, rb2->getVelocity());
				return CollisionCheck::CALCULATED;
			}

			// Dynamic x Static
			if (rb1 && !rb2) { 
				cirDynCirStat.calculate(circle1, rb1->getVelocity(), circle2);
				return CollisionCheck::CALCULATED;
			}
			else if (!rb1 && rb2) {
				cirDynCirStat.calculate(circle2, rb2->getVelocity(), circle1);
				return CollisionCheck::CALCULATED;
			}
		}
		return CollisionCheck::ERROR_TYPE;
	}

	void CircleCollidesCircle::
		calculate(CircleCollider * circleColliderDynamic, Vector2 velocityDynamic, CircleCollider * circleColliderStatic)
	{
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
