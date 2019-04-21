#include "CircleCollidesCircle.h"

namespace G1 {

	CircleCollidesCircle::CircleCollidesCircle()
	{
	}

	CollisionCheck CircleCollidesCircle::checkCollision(Collider * collider1, Collider * collider2)
	{
		CollisionCircle* circle1 = dynamic_cast<CollisionCircle*>(collider1);
		CollisionCircle* circle2 = dynamic_cast<CollisionCircle*>(collider2);

		if (circle1 && circle2) {
			return isColliding(collider1, collider2);
		}
		return CollisionCheck::WRONG_TYPE;
	}

	CollisionCheck CircleCollidesCircle::isColliding(Collider * cir1, Collider * cir2)
	{
		float distance = GMath::twoPointsDistance(cir1->getWorldPosition(), cir2->getWorldPosition());

		if (cir1->getFarthestPoint() + cir2->getFarthestPoint() >= distance)
			return CollisionCheck::COLLIDES;
		else
			return CollisionCheck::NOT_COLLIDES;
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
