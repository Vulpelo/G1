#include "CircleCollidesCircle.h"

namespace G1 {

	CircleCollidesCircle::CircleCollidesCircle()
	{
	}

	CollisionCheck CircleCollidesCircle::isColliding(Collider * collider1, Collider * collider2)
	{
		CollisionCircle* circle1 = dynamic_cast<CollisionCircle*>(collider1);
		CollisionCircle* circle2 = dynamic_cast<CollisionCircle*>(collider2);

		if (circle1 && circle2) {
			return CollisionCheck::NOT_COLLIDES;
		}
		return CollisionCheck::WRONG_TYPE;
	}


	CircleCollidesCircle::~CircleCollidesCircle()
	{
	}

}
