#include "RectangleCollidesRectangle.h"

namespace G1 {
	bool RectangleCollidesRectangle::check(Collider * rect1, Collider * rect2)
	{
		float additionalAngle = 90;
		float T[] = { rect1->getFarthestPointVector().Y, rect1->getFarthestPointVector().X };

		// THIS COLLIDER
		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2 P;
			P.setVectorByAngleAndLength(rect1->getWorldRotation() + additionalAngle*i, 1);

			// distance between two rectangles
			Vector2 dTmp;
			//dist = GMath::twoPointsDistance(rect2->getWorldPosition(), rect1->getWorldPosition());
			dTmp = rect2->getWorldPosition().invertY() - rect1->getWorldPosition().invertY();
			float dist = fabs(dTmp * P);

			// sum of max and min distance of vertex
			float vertDist = T[i];

			// figure 2: half diagonal
			float hDiag;
			Vector2 oR;
			// geting otherCollider farthest point and rotating it
			oR.setVectorByAngleAndLength
			(rect2->getWorldRotation() + rect2->getFarthestPointVector().angle(),
				rect2->getFarthestPoint());
			hDiag = fabs(oR * P);

			//Second diagonal check if is longer on new perspective
			oR.setVectorByAngleAndLength
			(rect2->getWorldRotation() + (rect2->getFarthestPointVector().invertY()).angle(),
				rect2->getFarthestPoint());
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

	RectangleCollidesRectangle::RectangleCollidesRectangle()
	{
	}

	CollisionCheck RectangleCollidesRectangle::checkCollision(Collider * collider1, Collider * collider2)
	{
		CollisionRectangle* rectangle1 = dynamic_cast<CollisionRectangle*>(collider1);
		CollisionRectangle* rectangle2 = dynamic_cast<CollisionRectangle*>(collider2);

		if (rectangle1 && rectangle2) {
			return isColliding(collider1, collider2);
		}
		return CollisionCheck::WRONG_TYPE;
	}

	CollisionCheck RectangleCollidesRectangle::isColliding(Collider * rect1, Collider * rect2)
	{
		if (check(rect1, rect2) && check(rect2, rect1))
		{
			return CollisionCheck::COLLIDES;
		}
		return CollisionCheck::NOT_COLLIDES;
	}


	RectangleCollidesRectangle::~RectangleCollidesRectangle()
	{
	}

}
