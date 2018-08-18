#pragma once

#include <SFML\Graphics.hpp>
#include "MathFunctions.h"
#include "Transform.h"

class SimpleShape
{
protected:
	double meshLocalPositionX, meshLocalPositionY;

	// World transform
	Transform wTransform;
	// Relative transform
	Transform rTransform;
	// First transform of a shape
	Transform begin_rTransform;

	double minuendOfRot;

	/* Shape is rotating with his own origin (middle of shape) [True]
	or shape is rotating by origin (middle) of the actor [False].
	Default is false*/
	bool ownOrigin;

	// Color of the shape
	sf::Color color;
public:
	SimpleShape();
	SimpleShape(sf::Color c);
	virtual void draw(sf::RenderWindow * w) = 0;

	/*=Transform=*/
	//position
	double getXWorldPosition();
	double getYWorldPosition();
	virtual void setWorldPosition(double x, double y);
	virtual void setLocalCoordinate(double aX, double aY);
	void additionalMeshLocalPosition(double x, double y);

	//rotation
	double getXWorldRotation();
	virtual void setWorldRotation(double x);
	double getXLocalRotation();
	virtual void setLocalRotation(double x);

	void rotationByOwnOrigin(bool ownOrigin);
};


class Circle : public SimpleShape
{
private:
	sf::CircleShape circle;
	double radius;
public:
	Circle(double radiusTemp, sf::Color);
	void setWorldPosition(double x, double y);
	void setWorldRotation(double x);
	void draw(sf::RenderWindow *);
	void setLocalCoordinate(double aX, double aY);
};


class Rectangle : public SimpleShape
{
private:
	sf::RectangleShape rectangle;
	double height, length;
public:
	Rectangle(double leng, double heig, sf::Color);
	void setWorldPosition(double x, double y);
	void setWorldRotation(double x);
	void draw(sf::RenderWindow *);
	void setLocalCoordinate(double aX, double aY);
};


class Triangle : public SimpleShape
{
private:
	double height, base;
public:
	Triangle(double heightZ, double baseZ);
	void setWorldPosition(double x, double y);
	void draw(sf::RenderWindow *);
};