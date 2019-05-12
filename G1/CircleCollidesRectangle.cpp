#include "CircleCollidesRectangle.h"

namespace G1 {

	CircleCollidesRectangle::CircleCollidesRectangle()
	{
	}

	CollisionCheck CircleCollidesRectangle::checkCollision(Collider * collider1, Collider * collider2)
	{
		RectangleCollider* rectangle = dynamic_cast<RectangleCollider*>(collider1);
		CircleCollider* circle = dynamic_cast<CircleCollider*>(collider2);

		if (rectangle && circle) {
			return isColliding(collider1, collider2);
		}


		rectangle = dynamic_cast<RectangleCollider*>(collider2);
		circle = dynamic_cast<CircleCollider*>(collider1);

		if (rectangle && circle) {
			return isColliding(collider2, collider1);
		}

		return CollisionCheck::WRONG_TYPE;
	}

	CollisionCheck CircleCollidesRectangle::isColliding(Collider * rect, Collider * cirl)
	{
		float distance =
			GMath::twoPointsDistance(rect->getWorldPosition().X, rect->getWorldPosition().Y,
				cirl->getWorldPosition().X, cirl->getWorldPosition().Y);

		// Does not overlap for sure
		if (cirl->getFarthestPoint() + rect->getFarthestPoint() < distance)
			return CollisionCheck::NOT_COLLIDES;
		// Does overlap for sure
		else if (cirl->getNearestPoint() + rect->getNearestPoint() >= distance)
			return CollisionCheck::COLLIDES;
		// Not sure, need extra check
		else {
			// TODO : instead Position struct use Vector2 for location
			float additionalAngle = 90;
			float T[] = { rect->getFarthestPointVector().Y, rect->getFarthestPointVector().X };

			for (int i = 0; i < 2; i++) {
				// New perspective vector
				Vector2 P;
				P.setVectorByAngleAndLength(rect->getWorldRotation() + additionalAngle*i, 1);

				Vector2 distance;
				distance = cirl->getWorldPosition().invertY() - rect->getWorldPosition().invertY();
				// fabs(distance * P) - distance between circle and rectangle on new perspective
				if (fabs(distance * P) > T[i] + cirl->getFarthestPoint()) {
					//not touching for sure

					return CollisionCheck::NOT_COLLIDES;
				}
			}
			return CollisionCheck::COLLIDES;
		}
	}


	CircleCollidesRectangle::~CircleCollidesRectangle()
	{
	}

}
