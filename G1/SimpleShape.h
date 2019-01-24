#pragma once

#include <SFML\Graphics.hpp>
#include "MathFunctions.h"
#include "Transform.h"
#include "Object.h"

class SimpleShape
{
protected:
	Object* parent;
	Transform transform;

	// Color of the shape
	sf::Color color;

public:
	SimpleShape();
	SimpleShape(sf::Color c);
	virtual void draw(sf::RenderWindow * w) = 0;

	void setParent(Object* parent);

	/*=Transform=*/
	void setPosition(double aX, double aY);
	void setTransform(Transform transform);
	Transform getTransform();

	//rotation
	float getRotation();
	void setRotation(double x);
};


class Circle : public SimpleShape
{
private:
	sf::CircleShape circle;
	float radius;
public:
	Circle(double radiusTemp, sf::Color);
	void draw(sf::RenderWindow *);
};


class Rectangle : public SimpleShape
{
private:
	sf::RectangleShape rectangle;
	float height, length;
public:
	Rectangle(double leng, double heig, sf::Color);
	void draw(sf::RenderWindow *);
};


class Triangle : public SimpleShape
{
private:
	float height, base;
public:
	Triangle(double heightZ, double baseZ);
	void draw(sf::RenderWindow *);
};