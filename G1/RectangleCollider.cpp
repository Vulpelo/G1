#include "RectangleCollider.h"

namespace G1 {

	RectangleCollider::RectangleCollider(float length, float height, float posX, float posY, float rot)
	{
		this->length = length;
		this->height = height;
		this->setTransform(Transform(posX, posY, rot));
		this->collisionType = 'r';
		this->farthestPoint = sqrtf((length*length) / 4.0f + (height*height) / 4.0f);
		this->nearestPoint = (length < height ? length / 2.0f : height / 2.0f);
	}

	Vector2 RectangleCollider::getFarthestPointVector() {
		return Vector2(this->length / 2.0f, this->height / 2.0f);
	}

	bool RectangleCollider::isCollidingWith(Collider *otherCollider)
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
