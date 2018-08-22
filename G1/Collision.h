#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "SimpleShape.h"
#include "MathFunctions.h"
#include "Vector2D.h"

class Collision : public SimpleShape
{
protected:
	//SimpleShape *collision;
	char collisionType;
	float farthestPoint;
	float nearestPoint;
	//not actually used
	void draw(sf::RenderWindow * w);
	bool rectangleOverlapsCircle(Collision*rect, Collision*cirl);
public:
	Collision();
	char getCollisionType();
	virtual bool isCollidingWith(Collision *otherCollider) = 0;
	
	// returns distance from origin of colider to the farthest point of colider
	float getFarthestPoint();
	// returns distance from origin of colider to the nearest point of colider
	float getNearestPoint();

	//the part of collider that is the farthest to the left (X), lowest (Y) 
	virtual double lowestX() = 0;
	virtual double lowestY() = 0;
	virtual double biggestX() = 0;
	virtual double biggestY() = 0;

	virtual bool rectangleOverlapsPoint(Position point) = 0;
	//returns radius in which you can tell is colliding or not. But calculations 
	//are more complex. (for rectangles)
	//virtual double preciseTouchRange(double otherColliderXCoordinate, double otherColliderYCoordinate) = 0;
	
};

class CollisionRectangle : public Collision
{
private:
	double height, length;

public:
	CollisionRectangle(double height, double length, double worldCoordinateX, double worldCoordinateY);
	bool isCollidingWith(Collision *otherCollider);

	double lowestX();
	double lowestY();
	double biggestX();
	double biggestY();
	//double preciseTouchRange(double otherColliderXCoordinate, double otherColliderYCoordinate);
	bool rectangleOverlapsPoint(Position point);
};

class CollisionCircle : public Collision
{
private:
	double radius;

public:
	CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY);
	bool isCollidingWith(Collision *otherCollider);
	double lowestX();
	double lowestY();
	double biggestX();
	double biggestY();
	//double preciseTouchRange(double otherColliderXCoordinate, double otherColliderYCoordinate);
	bool rectangleOverlapsPoint(Position point) {return false;};

};

#endif // !COLLISION_H
