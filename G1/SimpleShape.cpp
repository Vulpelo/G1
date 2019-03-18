#include <iostream>
#include "SimpleShape.h"

namespace G1 {

	SimpleShape::SimpleShape()
	{}

	//SimpleShape::SimpleShape(sf::Color c)
	//	: SimpleShape()
	//{
	//	color = c;
	//}

	//void SimpleShape::setParent(GameObject * parent)
	//{
	//	this->parent = parent;
	//}

	void SimpleShape::setPosition(float x, float y)
	{
		this->transform.position.X = x;
		this->transform.position.Y = y;
	}

	void SimpleShape::setTransform(Transform transform)
	{
		this->transform = transform;
	}

	Transform SimpleShape::getTransform()
	{
		return this->transform;
	}

	float SimpleShape::getRotation()
	{
		return this->transform.rotationX;
	}

	void SimpleShape::setRotation(float x)
	{
		this->transform.rotationX = x;
	}

	/////////////////////////////////////

	//Circle::Circle(double radiusT, sf::Color c)
	//	:radius(radiusT),
	//	SimpleShape(c)
	//{
	//	circle.setOrigin(sf::Vector2f(radius, radius));
	//	circle.setRadius(radius);
	//	circle.setPosition(transform.position.X, transform.position.Y);
	//	circle.setRotation(transform.rotationX);
	//	circle.setFillColor(color);
	//}

	//void Circle::draw(sf::RenderWindow * w)
	//{
	//	w->draw(circle);
	//}

	/////////////////////////////////////

	//Rectangle::Rectangle(double leng, double heig, sf::Color c)
	//	: length(leng), height(heig),
	//	SimpleShape(c)
	//{
	//	rectangle.setOrigin(sf::Vector2f(length / 2.0, height / 2.0));
	//	rectangle.setSize(sf::Vector2f(length, height));
	//	rectangle.setFillColor(color);
	//	rectangle.setPosition(transform.position.X + transform.position.X, transform.position.Y + transform.position.Y);
	//	rectangle.setRotation(transform.rotationX + transform.rotationX);
	//}

	//void Rectangle::draw(sf::RenderWindow * w)
	//{
	//	w->draw(rectangle);
	//}

	/////////////////////////////////////

	//Triangle::Triangle(double heightZ, double baseZ)
	//	:height(heightZ), base(baseZ) {}

	//void Triangle::draw(sf::RenderWindow *)
	//{
	//	std::cout << "-WIELOKAT (TROJKAT) NIEDOSTEPNY-\n";
	//}

}
