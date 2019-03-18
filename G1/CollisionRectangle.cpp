#include "CollisionRectangle.h"

namespace G1 {

	CollisionRectangle::CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY, float rot)
	{
		this->length = length;
		this->height = height;
		this->setTransform(Transform(worldCoordinateX, worldCoordinateY, rot));
		this->collisionType = 'r';
		this->farthestPoint = sqrt((length*length) / 4.0f + (height*height) / 4.0f);
		this->nearestPoint = (length < height ? length / 2.0f : height / 2.0f);
	}

	Vector2 CollisionRectangle::getFarthestPointVector() {
		return Vector2(this->length / 2.0, height / 2.0);
	}

	bool CollisionRectangle::isCollidingWith(Collision *otherCollider)
	{
		if (otherCollider->getCollisionType() == 'c') //for circle
		{
			return rectangleOverlapsCircle(this, otherCollider);
		}
		else if (otherCollider->getCollisionType() == 'r') //for rectangle
		{
			if (rectangleOverlapsRectangle(this, otherCollider) && rectangleOverlapsRectangle(otherCollider, this))
				return true;
		}
		return false;
	}

}
