#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "SimpleShape.h"
#include "MathFunctions.h"
#include "Vector2D.h"

class Collision : public SimpleShape
{
protected:
	char collisionType;
	float farthestPoint;
	float nearestPoint;
	//not actually used
	void draw(sf::RenderWindow * w);
	bool rectangleOverlapsCircle(Collision*rect, Collision*cirl);
	bool rectangleOverlapsRectangle(Collision*rect, Collision*otherRect);
	bool rectangleOverlapsPoint(Position point);

public:
	Collision();
	char getCollisionType();
	virtual bool isCollidingWith(Collision *otherCollider) = 0;

	virtual Vector2D getFarthestPointVector();
	// returns distance from origin of colider to the farthest point on the colider
	float getFarthestPoint();
	// returns distance from origin of colider to the nearest point on the colider
	float getNearestPoint();
};

class CollisionRectangle : public Collision
{
	double height, length;

public:
	CollisionRectangle(double length, double height, double worldCoordinateX, double worldCoordinateY, float rot = 0);
	bool isCollidingWith(Collision *otherCollider);
	Vector2D CollisionRectangle::getFarthestPointVector();
};

class CollisionCircle : public Collision
{
	double radius;

public:
	CollisionCircle(double radius, double worldCoordinateX, double worldCoordinateY);
	bool isCollidingWith(Collision *otherCollider);
};

#endif // !COLLISION_H
