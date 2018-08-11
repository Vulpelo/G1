#pragma once

#include <SFML\Graphics.hpp>
#include "MathFunctions.h"

class SimpleShape
{
protected:
	double scaleX, scaleY;
	double meshLocalPositionX, meshLocalPositionY;
	double localCoordinateX, localCoordinateY;
	double worldCoordinateX, worldCoordinateY;
	double localRotationX;
	double worldRotationX;
	/*shape is rotating with his own origin (middle of shape)
	or is rotating by origin (middle) of the actor
	Defoult is false*/
	bool ownOrigin;
	double beginLocalCoordinateX, beginLocalCoordinateY;
	double beginRotFromObject;
	double minuendOfRot;
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

	void setScale(double sX, double sY);
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