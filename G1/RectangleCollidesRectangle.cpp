#include "RectangleCollidesRectangle.h"

namespace G1 {

	RectangleCollidesRectangle::RectangleCollidesRectangle()
	{
	}

	CollisionCheck RectangleCollidesRectangle::checkCollision(Collider * collider1, Collider * collider2)
	{
		CollisionRectangle* rectangle1 = dynamic_cast<CollisionRectangle*>(collider1);
		CollisionRectangle* rectangle2 = dynamic_cast<CollisionRectangle*>(collider2);

		if (rectangle1 && rectangle2) {
			// TODO: CHECK COLLISION CODE
			return CollisionCheck::NOT_COLLIDES;
		}
		return CollisionCheck::WRONG_TYPE;
	}

	CollisionCheck RectangleCollidesRectangle::isColliding(Collider * collider1, Collider * collider2)
	{
		return CollisionCheck();
	}


	RectangleCollidesRectangle::~RectangleCollidesRectangle()
	{
	}

}
