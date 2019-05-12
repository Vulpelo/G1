#include "CircleCollider.h"

namespace G1 {

	CircleCollider::CircleCollider(float radius, float worldCoordinateX, float worldCoordinateY)
	{
		this->radius = radius;
		this->setTransform(Transform(worldCoordinateX, worldCoordinateY, 0));
		this->collisionType = 'c';
		this->farthestPoint = radius;
		this->nearestPoint = radius;
	}

	bool CircleCollider::isCollidingWith(Collider *otherCollider)
	{
		if (otherCollider->getCollisionType() == 'c') // for circle
		{
			float distance = GMath::twoPointsDistance(this->getWorldPosition(), otherCollider->getWorldPosition());

			if (this->radius + otherCollider->getFarthestPoint() >= distance)
				return true;
			else
				return false;
		}
		else if (otherCollider->getCollisionType() == 'r') //for rectangle
		{
			return rectangleOverlapsCircle(otherCollider, this);
		}
		return false;
	}

}
