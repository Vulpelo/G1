#include "Collision.h"

void Collision::draw(sf::RenderWindow * w)
{}

Collision::Collision()
	: SimpleShape()
{

}


char Collision::getCollisionType()
{
	return collisionType;
}

//bool Collision::isCollidingWith(Collision *otherCollider)
//{
//
//}


//////////////////////////////////////////////////////////////////////////

CollisionRectangle::CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY)
{
	this->length = length;
	this->height = height;
	this->worldCoordinateX = worldCoordinateX;
	this->worldCoordinateY = worldCoordinateY;
	this->collisionType = 'r';
}

double CollisionRectangle::lowestX()
{
	return this->getXWorldPosition() - (this->length / 2.0);
}
double CollisionRectangle::lowestY()
{//JEwszcze sprawdzic
	return this->getYWorldPosition() - (this->height / 2.0);
}
double CollisionRectangle::biggestX()
{
	return this->getXWorldPosition() + (this->length / 2.0);
}
double CollisionRectangle::biggestY()
{//JEwszcze sprawdzic
	return this->getYWorldPosition() + (this->height / 2.0);
}

bool CollisionRectangle::isCollidingWith(Collision *otherCollider)
{
	double distance = 
		MathFunction::twoPointsDistance(this->worldCoordinateX, this->worldCoordinateY, 
		otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition());

	if (otherCollider->getCollisionType() == 'c') //for circle
	{
		double distance = -1;

		if (otherCollider->getXWorldPosition() > this->biggestX())
		{
			if (otherCollider->getYWorldPosition() > this->biggestY())
			{
				//gorny prawy wierzcholek
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->biggestX(), this->biggestY());
			}
			else if (otherCollider->getYWorldPosition() < this->lowestY())
			{
				//dolny prawy wierzcholek 
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->biggestX(), this->lowestY());
			}
			else
			{
				//prawa strona prostokata
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->biggestX(), otherCollider->getYWorldPosition());
			}
		}
		else if (otherCollider->getXWorldPosition() < this->lowestX())
		{
			if (otherCollider->getYWorldPosition() > this->biggestY())
			{
				//gorny lewy wierzcholek
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->lowestX(), this->biggestY());
			}
			else if (otherCollider->getYWorldPosition() < this->lowestY())
			{
				//dolny lewy wierzcholek 
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->lowestX(), this->lowestY());
			}
			else
			{
				//lewa strona prostokata
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->lowestX(), otherCollider->getYWorldPosition());
			}
		}
		else if (otherCollider->getYWorldPosition() > this->biggestY())
		{
			//gorna storna prostokata
			distance =
				MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
					otherCollider->getXWorldPosition(), this->biggestY());
		}
		else if (otherCollider->getYWorldPosition() < this->lowestY())
		{
			//dolna strona prostokata
			distance =
				MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
					otherCollider->getXWorldPosition(), this->lowestY());
		}
		else
		{
			//jak nie jest na zewnatrz prostokata to jest wewnatrz
			return true;
		}
		return distance <= otherCollider->biggestX() ? true : false;
	}
	else if (otherCollider->getCollisionType() == 'r') //for rectangle
	{
		if ( this->lowestX() > otherCollider->biggestX() || otherCollider->lowestX() > this->biggestX())
		{
			return false;
		};
		if (this->biggestY() < otherCollider->lowestY() || otherCollider->biggestY() < this->lowestY())
		{
			return false;
		};
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////

CollisionCircle::CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY)
{
	this->radius = radius;
	this->worldCoordinateX = worldCoordinateX;
	this->worldCoordinateX = worldCoordinateY;
	this->collisionType = 'c';
}

//double CollisionCircle::preciseTouchRange(double otherColliderXCoordinate, double otherColliderYCoordinate)
//{
//	return radius;
//}

bool CollisionCircle::isCollidingWith(Collision *otherCollider)
{
	double distance=-1;
	
	if (otherCollider->getCollisionType() == 'c') // for circle
	{
		distance = MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
			otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition());

		if (this->radius + otherCollider->lowestX() >= distance)
			return true;
		else
			return false;
	}
	else if (otherCollider->getCollisionType() == 'r') //for rectangle
	{
		if (otherCollider->getXWorldPosition() > this->biggestX())
		{
			if (this->getYWorldPosition() > otherCollider->biggestY())
			{
				//gorny prawy wierzcholek
				distance =
					MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
						otherCollider->biggestX(), otherCollider->biggestY());
			}
			else if (this->getYWorldPosition() < otherCollider->lowestY())
			{
				//dolny prawy wierzcholek 
				distance =
					MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
						otherCollider->biggestX(), otherCollider->lowestY());
			}
			else
			{
				//prawa strona prostokata
				distance =
					MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
						otherCollider->biggestX(), this->getYWorldPosition());
			}
		}
		else if (this->getXWorldPosition() < otherCollider->lowestX())
		{
			if (this->getYWorldPosition() > otherCollider->biggestY())
			{
				//gorny lewy wierzcholek
				distance =
					MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
						this->lowestX(), this->biggestY());
			}
			else if (this->getYWorldPosition() < otherCollider->lowestY())
			{
				//dolny lewy wierzcholek 
				distance =
					MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
						otherCollider->lowestX(), otherCollider->lowestY());
			}
			else
			{
				//lewa strona prostokata
				distance =
					MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
						otherCollider->lowestX(), this->getYWorldPosition());
			}
		}
		else if (this->getYWorldPosition() > otherCollider->biggestY())
		{
			//gorna storna prostokata
			distance =
				MathFunction::twoPointsDistance(otherCollider->getXWorldPosition(), otherCollider->getYWorldPosition(),
					otherCollider->getXWorldPosition(), this->biggestY());
		}
		else if (this->getYWorldPosition() < otherCollider->lowestY())
		{
			//dolna strona prostokata
			distance =
				MathFunction::twoPointsDistance(this->getXWorldPosition(), this->getYWorldPosition(),
					this->getXWorldPosition(), otherCollider->lowestY());
		}
		else
		{
			//jak nie jest na zewnatrz prostokata to jest wewnatrz
			return true;
		}
		return distance <= this->biggestX() ? true : false;
	}
	return false;
}

double CollisionCircle::lowestX()
{
	return radius;
}
double CollisionCircle::lowestY()
{
	return radius;
}
double CollisionCircle::biggestX()
{
	return radius;
}
double CollisionCircle::biggestY()
{
	return radius;
}