#include "Collision.h"

Collision::Collision()
	: SimpleShape()
{

}

void Collision::draw(sf::RenderWindow * w)
{}

char Collision::getCollisionType()
{
	return collisionType;
}

float Collision::getFarthestPoint()
{
	return this->farthestPoint;
}

Vector2D Collision::getFarthestPointVector() { return Vector2D(); }

float Collision::getNearestPoint()
{
	return this->nearestPoint;
}

bool Collision::rectangleOverlapsCircle(Collision * rect, Collision * cirl)
{
	float distance =
		GMath::twoPointsDistance(rect->wTransform.position.X, rect->wTransform.position.Y,
			cirl->getXWorldPosition(), cirl->getYWorldPosition());

	// Does not overlap for sure
	if (cirl->getFarthestPoint() + rect->getFarthestPoint() < distance)
		return false;
	// Does overlap for sure
	else if (cirl->getNearestPoint() + rect->getNearestPoint() >= distance)
		return true;
	// Not sure, need extra check
	else {
		// TODO : instead Position struct use Vector2 for location
		Vector2D rec(rect->wTransform.position); Vector2D cir(cirl->wTransform.position);
		Vector2D nV = (rec - cir).normalize();
		nV = cir + nV * cirl->getFarthestPoint();

		return rect->rectangleOverlapsPoint(Position(nV.X, nV.Y));
	}
}

//////////////////////////////////////////////////////////////////////////

CollisionRectangle::CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY, float rot)
{
	this->length = length;
	this->height = height;
	this->wTransform.position.X = worldCoordinateX;
	this->wTransform.position.Y = worldCoordinateY;
	this->wTransform.rotationX = rot;
	this->collisionType = 'r';
	this->farthestPoint = sqrt( (length*length)/4.0f + (height*height)/4.0f );
	this->nearestPoint = ( length<height ? length/2.0f : height/2.0f );
}

double CollisionRectangle::lowestX()
{
	return this->getXWorldPosition() - (this->length / 2.0);
}
double CollisionRectangle::lowestY()
{//JEwszcze sprawdzic
	return this->getYWorldPosition() + (this->height / 2.0);
}
double CollisionRectangle::biggestX()
{
	return this->getXWorldPosition() + (this->length / 2.0);
}
double CollisionRectangle::biggestY()
{//JEwszcze sprawdzic
	return this->getYWorldPosition() - (this->height / 2.0);
}

Vector2D CollisionRectangle::getFarthestPointVector() {
	return Vector2D(this->length/2.0, height/2.0);
}


bool CollisionRectangle::rectangleOverlapsPoint(Position point)
{
	if (this->lowestX() <= point.X && point.X <= this->biggestX() && this->biggestY() <= point.Y && point.Y <= this->lowestY())
	{
		return true;
	}
	return false;
}

bool CollisionRectangle::isCollidingWith(Collision *otherCollider)
{
	if (otherCollider->getCollisionType() == 'c') //for circle
	{
		return rectangleOverlapsCircle(this, otherCollider);
	}
	else if (otherCollider->getCollisionType() == 'r') //for rectangle
	{
		// TODO: CHANGE COLLISION ALGORYTHM FOR RECTANGLE. CHECKING COL. FOR ROTATED COLIDERS

		float additionalAngle = 90;

		float T[] = { height / 2.0, length / 2.0 };
		
		// THIS COLLIDER
		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2D P;
			P.setVectorByAngleAndLength(this->wTransform.rotationX + additionalAngle*i, 1);

			// distance between two rectangles
			Vector2D dTmp;
			dTmp = otherCollider->wTransform.position.invertY() - this->wTransform.position.invertY();
			float dist = fabs(dTmp * P);

			// sum of max and min distance of vertex
			float vertDist = T[i];

			// figure 2: half diagonal
			float hDiag;
			Vector2D oR;
			// geting otherCollider farthest point and rotating it
			oR.setVectorByAngleAndLength
			(otherCollider->wTransform.rotationX + otherCollider->getFarthestPointVector().angle(),
				otherCollider->getFarthestPoint());
			hDiag = fabs(oR * P);

			//Second diagonal check if is longer on new perspective
			oR.setVectorByAngleAndLength
			(otherCollider->wTransform.rotationX + (otherCollider->getFarthestPointVector().invertY()).angle(),
				otherCollider->getFarthestPoint());
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

		T[0] = otherCollider->getFarthestPointVector().Y;
		T[1] = otherCollider->getFarthestPointVector().X;

		// OTHER COLLIDER
		for (int i = 0; i < 2; i++) {

			// New perspective vector
			Vector2D P;
			P.setVectorByAngleAndLength(otherCollider->wTransform.rotationX + additionalAngle*i, 1);

			// two rectangle distance
			Vector2D dTmp;
			dTmp = this->wTransform.position.invertY() - otherCollider->wTransform.position.invertY();
			float dist = fabs(dTmp * P);

			// sum of max and min distance of vertex
			float vertDist = T[i];

			// figure 2: half diagonal
			float hDiag;
			Vector2D oR;
			// geting otherCollider farthest point and rotating it
			oR.setVectorByAngleAndLength
			(this->wTransform.rotationX + this->getFarthestPointVector().angle(),
				this->getFarthestPoint());
			hDiag = fabs(oR * P);

			//Second diagonal check if is longer on new perspective
			oR.setVectorByAngleAndLength
			(this->wTransform.rotationX + (this->getFarthestPointVector().invertY()).angle(),
				this->getFarthestPoint());
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
	return false;
}

//////////////////////////////////////////////////////////////////////////

CollisionCircle::CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY)
{
	this->radius = radius;
	this->wTransform.position.X = worldCoordinateX;
	this->wTransform.position.Y = worldCoordinateY;
	this->collisionType = 'c';
	this->farthestPoint = radius;
	this->nearestPoint = radius;
}

//double CollisionCircle::preciseTouchRange(double otherColliderXCoordinate, double otherColliderYCoordinate)
//{
//	return radius;
//}

bool CollisionCircle::isCollidingWith(Collision *otherCollider)
{
	if (otherCollider->getCollisionType() == 'c') // for circle
	{
		float distance = GMath::twoPointsDistance(this->wTransform.position, this->wTransform.position);

		if (this->radius + otherCollider->lowestX() >= distance)
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

double CollisionCircle::lowestX()
{
	return this->getXWorldPosition() - radius;
}
double CollisionCircle::lowestY()
{
	return this->getYWorldPosition() + radius;
}
double CollisionCircle::biggestX()
{
	return this->getXWorldPosition() + radius;
}
double CollisionCircle::biggestY()
{
	return this->getYWorldPosition() - radius;
}
