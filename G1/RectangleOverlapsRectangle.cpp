#include "RectangleOverlapsRectangle.h"

namespace G1 {
	bool RectangleOverlapsRectangle::check(Collider * rect1, Collider * rect2)
	{
		float additionalAngle = 90;
		float T[] = { rect1->getFarthestPointVector().y, rect1->getFarthestPointVector().x };

		// THIS COLLIDER
		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2 P = Vector2::byAngleAndLength(rect1->getWorldRotation() + additionalAngle*i, 1);

			// distance between two rectangles
			Vector2 dTmp;
			dTmp = rect2->getWorldPosition().invertY() - rect1->getWorldPosition().invertY();
			float dist = fabs(dTmp * P);

			// figure 2: half diagonal
			float hDiag;
			Vector2 oR;
			// geting otherCollider farthest point and rotating it
			oR = oR.byAngleAndLength(
				rect2->getWorldRotation() + rect2->getFarthestPointVector().angle(),
				rect2->getFarthestPoint()
			);
			hDiag = fabs(oR * P);

			//Second diagonal check if is longer on new perspective
			oR = oR.byAngleAndLength(
				rect2->getWorldRotation() + rect2->getFarthestPointVector().invertY().angle(),
				rect2->getFarthestPoint()
			);
			float tmp = fabs(oR * P);

			if (hDiag < tmp) {
				hDiag = tmp;
			}

			// rzutowanie na nowy wektor
			// sum of max and min distance of vertex
			T[i] += hDiag;

			if (dist > T[i]) {
				//not touching for sure
				return false;
			}
		}
		return true;
	}

	RectangleOverlapsRectangle::RectangleOverlapsRectangle()
	{
	}

	OverlappingCheck RectangleOverlapsRectangle::checkCollision(Collider * collider1, Collider * collider2)
	{
		RectangleCollider* rectangle1 = dynamic_cast<RectangleCollider*>(collider1);
		RectangleCollider* rectangle2 = dynamic_cast<RectangleCollider*>(collider2);

		if (rectangle1 && rectangle2) {
			return isColliding(collider1, collider2);
		}
		return OverlappingCheck::WRONG_TYPE;
	}

	OverlappingCheck RectangleOverlapsRectangle::isColliding(Collider * rect1, Collider * rect2)
	{
		if (check(rect1, rect2) && check(rect2, rect1))
		{
			return OverlappingCheck::OVERLAPPING;
		}
		return OverlappingCheck::NOT_OVERLAPPING;
	}


	RectangleOverlapsRectangle::~RectangleOverlapsRectangle()
	{
	}

}
