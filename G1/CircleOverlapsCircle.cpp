#include "CircleOverlapsCircle.h"

namespace G1 {

	CircleOverlapsCircle::CircleOverlapsCircle()
	{
	}

	OverlappingCheck CircleOverlapsCircle::checkCollision(Collider * collider1, Collider * collider2)
	{
		CircleCollider* circle1 = dynamic_cast<CircleCollider*>(collider1);
		CircleCollider* circle2 = dynamic_cast<CircleCollider*>(collider2);

		if (circle1 && circle2) {
			return isColliding(collider1, collider2);
		}
		return OverlappingCheck::WRONG_TYPE;
	}

	OverlappingCheck CircleOverlapsCircle::isColliding(Collider * cir1, Collider * cir2)
	{
		float distance = GMath::twoPointsDistance(cir1->getWorldPosition(), cir2->getWorldPosition());

		if (cir1->getFarthestPoint() + cir2->getFarthestPoint() >= distance)
			return OverlappingCheck::OVERLAPPING;
		else
			return OverlappingCheck::NOT_OVERLAPPING;
	}


	CircleOverlapsCircle::~CircleOverlapsCircle()
	{
	}

}
