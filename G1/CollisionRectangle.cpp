#include "CollisionRectangle.h"

namespace G1 {

	CollisionRectangle::CollisionRectangle(float length, float height, float worldCoordinateX, float worldCoordinateY, float rot)
	{
		this->length = length;
		this->height = height;
		this->setTransform(Transform(worldCoordinateX, worldCoordinateY, rot));
		this->collisionType = 'r';
		this->farthestPoint = sqrtf((length*length) / 4.0f + (height*height) / 4.0f);
		this->nearestPoint = (length < height ? length / 2.0f : height / 2.0f);
	}

	Vector2 CollisionRectangle::getFarthestPointVector() {
		return Vector2(this->length / 2.0f, height / 2.0f);
	}

	bool CollisionRectangle::isCollidingWith(Collider *otherCollider)
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
