#include "CollisionCircle.h"

#pragma region CollisionCircle

CollisionCircle::CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY)
{
	this->radius = radius;
	this->setTransform(Transform(worldCoordinateX, worldCoordinateY, 0));
	this->collisionType = 'c';
	this->farthestPoint = radius;
	this->nearestPoint = radius;
}

bool CollisionCircle::isCollidingWith(Collision *otherCollider)
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

#pragma endregion
