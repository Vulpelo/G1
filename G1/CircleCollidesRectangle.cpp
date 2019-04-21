#include "CircleCollidesRectangle.h"

namespace G1 {

	CircleCollidesRectangle::CircleCollidesRectangle()
	{
	}

	CollisionCheck CircleCollidesRectangle::isColliding(Collider * collider1, Collider * collider2)
	{
		CollisionRectangle* rectangle = dynamic_cast<CollisionRectangle*>(collider1);
		CollisionCircle* circle = dynamic_cast<CollisionCircle*>(collider2);

		if (rectangle && circle) {
			// TODO: CHECK COLLISION CODE
			return CollisionCheck::NOT_COLLIDES;
		}


		rectangle = dynamic_cast<CollisionRectangle*>(collider2);
		circle = dynamic_cast<CollisionCircle*>(collider1);

		if (rectangle && circle) {
			// TODO: CHECK COLLISION CODE
			return CollisionCheck::NOT_COLLIDES;
		}

		return CollisionCheck::WRONG_TYPE;
	}


	CircleCollidesRectangle::~CircleCollidesRectangle()
	{
	}

}
