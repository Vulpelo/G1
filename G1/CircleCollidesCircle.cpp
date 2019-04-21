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
			// TODO: CHECK COLLISION CODE
			return CollisionCheck::NOT_COLLIDES;
		}
		return CollisionCheck::WRONG_TYPE;
	}

	CollisionCheck CircleCollidesCircle::isColliding(Collider * collider1, Collider * collider2)
	{
		return CollisionCheck();
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
