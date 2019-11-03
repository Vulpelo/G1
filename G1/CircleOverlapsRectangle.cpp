#include "CircleOverlapsRectangle.h"

namespace G1 {

	CircleOverlapsRectangle::CircleOverlapsRectangle()
	{
	}

	OverlappingCheck CircleOverlapsRectangle::checkCollision(Collider * collider1, Collider * collider2)
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

		return OverlappingCheck::WRONG_TYPE;
	}

	OverlappingCheck CircleOverlapsRectangle::isColliding(Collider * rect, Collider * cirl)
	{
		Vector2 cirlWorldPosition = cirl->getWorldPosition();
		Vector2 rectWorldPosition = rect->getWorldPosition();

		float distance =
			GMath::twoPointsDistance(rect->getWorldPosition().x, rect->getWorldPosition().y,
				cirl->getWorldPosition().x, cirl->getWorldPosition().y);

		// Does not overlap for sure
		if (cirl->getFarthestPoint() + rect->getFarthestPoint() < distance)
			return OverlappingCheck::NOT_OVERLAPPING;
		// Does overlap for sure
		else if (cirl->getNearestPoint() + rect->getNearestPoint() >= distance)
			return OverlappingCheck::OVERLAPPING;
		// Not sure, need extra check
		else {

			float maxRectLength = rect->getFarthestPoint();
			float recAddAngle = rect->getFarthestPointVector().angle();
			Vector2 p1 = Vector2::byAngleAndLength(recAddAngle + rect->getWorldRotation(), maxRectLength) + rectWorldPosition;
			Vector2 p2 = Vector2::byAngleAndLength(-recAddAngle + rect->getWorldRotation(), maxRectLength) + rectWorldPosition;
			Vector2 p3 = Vector2::byAngleAndLength(180 + recAddAngle + rect->getWorldRotation(), maxRectLength) + rectWorldPosition;
			Vector2 p4 = Vector2::byAngleAndLength(180 - recAddAngle + rect->getWorldRotation(), maxRectLength) + rectWorldPosition;

			Segment lines[4] = {
				Segment(p1, p2),
				Segment(p2, p3),
				Segment(p3, p4),
				Segment(p4, p1),
			};

			for (size_t i = 0; i < 4; i++) {
				if (lines[i].pointRelativeLine(cirlWorldPosition) > 0 &&
					lines[(i + 1) % 4].pointRelativeLine(cirlWorldPosition) > 0) 
				{
					// found right/closest apex

					if ((lines[i].getPoint2() - cirlWorldPosition).lengthNoSqrt() < cirl->getFarthestPoint() * cirl->getFarthestPoint()) {
						// apex in circle
						return OverlappingCheck::OVERLAPPING;
					}
					// at circle position, it needs to contain apex if want to overlap
					return OverlappingCheck::NOT_OVERLAPPING;
				}
			}


			// TODO: Circle x Rectamgle overlap on apexes check
			float additionalAngle = 90;
			float T[] = { rect->getFarthestPointVector().y, rect->getFarthestPointVector().x };

			for (int i = 0; i < 2; i++) {
				// New perspective vector
				Vector2 P = Vector2::byAngleAndLength(rect->getWorldRotation() + additionalAngle*i, 1);

				Vector2 distance;
				distance = cirl->getWorldPosition().invertY() - rect->getWorldPosition().invertY();
				// fabs(distance * P) - distance between circle and rectangle on new perspective
				if (fabs(distance * P) > T[i] + cirl->getFarthestPoint()) {
					//not touching for sure

					return OverlappingCheck::NOT_OVERLAPPING;
				}
			}
			return OverlappingCheck::OVERLAPPING;
		}
	}


	CircleOverlapsRectangle::~CircleOverlapsRectangle()
	{
	}

}
