#include "Collider.h"

namespace G1 {

	Collider::Collider()
		: Component()
	{
		this->overlappable = true;
	}

	void Collider::draw(sf::RenderWindow * w)
	{}

	char Collider::getCollisionType()
	{
		return collisionType;
	}

	bool Collider::isOverlappable()
	{
		return this->overlappable;
	}

	void Collider::setOverlappable(bool overlappable)
	{
		this->overlappable = overlappable;
	}

	Vector2 Collider::getFarthestPointVector()
	{
		return Vector2();
	}

	float Collider::getFarthestPoint()
	{
		return this->farthestPoint;
	}

	float Collider::getNearestPoint()
	{
		return this->nearestPoint;
	}

	bool Collider::rectangleOverlapsCircle(Collider * rect, Collider * cirl)
	{
		float distance =
			GMath::twoPointsDistance(rect->getWorldPosition().X, rect->getWorldPosition().Y,
				cirl->getWorldPosition().X, cirl->getWorldPosition().Y);

		// Does not overlap for sure
		if (cirl->getFarthestPoint() + rect->getFarthestPoint() < distance)
			return false;
		// Does overlap for sure
		else if (cirl->getNearestPoint() + rect->getNearestPoint() >= distance)
			return true;
		// Not sure, need extra check
		else {
			// TODO : instead Position struct use Vector2 for location
			float additionalAngle = 90;
			float T[] = { rect->getFarthestPointVector().Y, rect->getFarthestPointVector().X };

			for (int i = 0; i < 2; i++) {
				// New perspective vector
				Vector2 P;
				P.setVectorByAngleAndLength(rect->getTransform().rotationX + additionalAngle*i, 1);

				Vector2 distance;
				distance = cirl->getWorldPosition().invertY() - this->getWorldPosition().invertY();
				// fabs(distance * P) - distance between circle and rectangle on new perspective
				if (fabs(distance * P) > T[i] + cirl->getFarthestPoint()) {
					//not touching for sure
					return false;
				}
			}
			return true;
		}
	}

	bool Collider::rectangleOverlapsRectangle(Collider * rect, Collider * otherRect)
	{
		float additionalAngle = 90;
		float T[] = { rect->getFarthestPointVector().Y, rect->getFarthestPointVector().X };

		// THIS COLLIDER
		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2 P;
			P.setVectorByAngleAndLength(rect->getTransform().rotationX + additionalAngle*i, 1);

			// distance between two rectangles
			Vector2 dTmp;
			dTmp = otherRect->getWorldPosition().invertY() - rect->getWorldPosition().invertY();
			float dist = fabs(dTmp * P);

			// sum of max and min distance of vertex
			float vertDist = T[i];

			// figure 2: half diagonal
			float hDiag;
			Vector2 oR;
			// geting otherCollider farthest point and rotating it
			oR.setVectorByAngleAndLength
			(otherRect->getTransform().rotationX + otherRect->getFarthestPointVector().angle(),
				otherRect->getFarthestPoint());
			hDiag = fabs(oR * P);

			//Second diagonal check if is longer on new perspective
			oR.setVectorByAngleAndLength
			(otherRect->getTransform().rotationX + (otherRect->getFarthestPointVector().invertY()).angle(),
				otherRect->getFarthestPoint());
			float tmp = fabs(oR * P);
			if (hDiag < tmp) {
				hDiag = tmp;
			}

			// rzutowanie na nowy wektor
			vertDist += hDiag;

			if (dist > vertDist)
			{
				//not touching for sure
				return false;
			}
		}
		return true;
	}

	bool Collider::rectangleOverlapsPoint(Vector2 point)
	{
		float additionalAngle = 90;
		float T[] = { this->getFarthestPointVector().Y, this->getFarthestPointVector().X };

		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2 P;
			P.setVectorByAngleAndLength(this->getTransform().rotationX + additionalAngle*i, 1);

			Vector2 dTmp;
			dTmp = Vector2(point) - this->getWorldPosition().invertY(); // INVERT ??
			float dist = fabs(dTmp * P); // distance between point and rectangle on new perspective

			if (dist > T[i])
			{
				//not touching for sure
				return false;
			}
		}
		return true;
	}

}
