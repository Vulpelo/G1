#include <iostream>
#include "SimpleShape.h"

SimpleShape::SimpleShape() 
	: ownOrigin(false) 
{
	this->beginRotFromObject = 0;
	this->beginLocalCoordinateX = 0;
	this->beginLocalCoordinateY = 0;
	this->meshLocalPositionX = 0;
	this->meshLocalPositionY = 0;
}

SimpleShape::SimpleShape(sf::Color c) 
	: SimpleShape()
{
	color = c;
}

void SimpleShape::setWorldRotation(double x)
{
	wTransform.rotationX = x;
}

void SimpleShape::setWorldPosition(double x, double y)
{
	if (beginLocalCoordinateX + meshLocalPositionX != 0 || beginLocalCoordinateY + meshLocalPositionY != 0)
	{
		std::cout << this << "-RX " << wTransform.rotationX << "::X " << rTransform.position.X << ":Y " << rTransform.position.Y;
		this->beginRotFromObject = MathFunction::vectorAngle(beginLocalCoordinateX + meshLocalPositionX, -beginLocalCoordinateY + meshLocalPositionY);

		//double beginRotFromObject = atan(rTransform.position.X / rTransform.position.Y * 180 * M_PI);
		double c = sqrt((beginLocalCoordinateX + meshLocalPositionX)*(beginLocalCoordinateX + meshLocalPositionX)
			+ (beginLocalCoordinateY + meshLocalPositionY)*(beginLocalCoordinateY + meshLocalPositionY));
		//rTransform.position.X = c * sin((worldRotationX - localRotationX + beginRotFromObject)*M_PI / 180);
		rTransform.position.X = c * sin((wTransform.rotationX + beginRotFromObject)*M_PI / 180);

		if (wTransform.rotationX >= minuendOfRot - beginRotFromObject && wTransform.rotationX <= minuendOfRot + 180 - beginRotFromObject)
		{
			rTransform.position.Y = sqrt(c*c - rTransform.position.X*rTransform.position.X);
			std::cout << "::CON1 : " << beginRotFromObject << ";90 " << 90 - beginRotFromObject << ";270 " << 270 - beginRotFromObject;
		}
		else
		{
			rTransform.position.Y = -sqrt(c*c - rTransform.position.X*rTransform.position.X);
			std::cout << "::CON2 : " << beginRotFromObject << ";90 " << 90 - beginRotFromObject << ";270 " << 270 - beginRotFromObject;
		}
		if (minuendOfRot == 270)
			rTransform.position.Y = -rTransform.position.Y;
		std::cout << std::endl;

	}
	wTransform.position.X = rTransform.position.X + x;
	wTransform.position.Y = rTransform.position.Y - y;

}

void SimpleShape::setLocalCoordinate(double aX, double aY)
{
	this->rTransform.position.X = aX + meshLocalPositionX;
	this->beginLocalCoordinateX = aX;
	this->rTransform.position.Y = -aY - meshLocalPositionY;
	this->beginLocalCoordinateY = -aY;
}

void SimpleShape::additionalMeshLocalPosition(double x, double y)
{
	meshLocalPositionX = x;
	meshLocalPositionY = y;
}


void SimpleShape::rotationByOwnOrigin(bool ownOrigin)
{
	this->ownOrigin = ownOrigin;
}

double SimpleShape::getXWorldPosition()
{
	return wTransform.position.X + rTransform.position.X;
}

double SimpleShape::getYWorldPosition()
{
	return wTransform.position.Y + rTransform.position.Y;
}

double SimpleShape::getXWorldRotation()
{
	return wTransform.rotationX;
}
double SimpleShape::getXLocalRotation()
{
	return rTransform.rotationX;
}
void SimpleShape::setLocalRotation(double x)
{
	this->rTransform.rotationX = x;
}

/////////////////////////////////////

Circle::Circle(double radiusT, sf::Color c)
	:radius(radiusT),
	SimpleShape(c)
{

	circle.setOrigin(sf::Vector2f(radius, radius));
	circle.setRadius(radius);
	circle.setPosition(wTransform.position.X + rTransform.position.X, wTransform.position.Y + rTransform.position.Y);
	circle.setRotation(wTransform.rotationX + rTransform.rotationX);
	circle.setFillColor(color);
}

void Circle::setWorldPosition(double x, double y)
{
	SimpleShape::setWorldPosition(x, y);

	circle.setPosition(wTransform.position.X, wTransform.position.Y);
}

void Circle::setWorldRotation(double x)
{
	SimpleShape::setWorldRotation(x);
	circle.setRotation(wTransform.rotationX + rTransform.rotationX);
}

void Circle::draw(sf::RenderWindow * w)
{
	w->draw(circle);
}

void Circle::setLocalCoordinate(double aX, double aY)
{
	if (ownOrigin)
	{
		circle.setOrigin(sf::Vector2f(radius, radius));
		SimpleShape::setLocalCoordinate(aX, aY);
	}
	else if (ownOrigin == false)
		circle.setOrigin(sf::Vector2f(radius - aX, radius + aY));

	//!! this->beginRotFromObject = MathFunction::vectorAngle(rTransform.position.X, -rTransform.position.Y);
	this->beginRotFromObject = MathFunction::vectorAngle(beginLocalCoordinateX + meshLocalPositionX, -beginLocalCoordinateY - meshLocalPositionY);
	if (this->beginRotFromObject > 270)
		this->minuendOfRot = 450;
	else if (this->beginRotFromObject > 90)
		this->minuendOfRot = 270;
	else
		this->minuendOfRot = 90;
}
/////////////////////////////////////

Rectangle::Rectangle(double leng, double heig, sf::Color c)
	: length(leng), height(heig),
	SimpleShape(c)
{
	rectangle.setOrigin(sf::Vector2f(length/2.0, height/2.0));
	rectangle.setSize(sf::Vector2f(length, height));
	rectangle.setFillColor(color);
	rectangle.setPosition(wTransform.position.X + rTransform.position.X, wTransform.position.Y + rTransform.position.Y);
	rectangle.setRotation(wTransform.rotationX + rTransform.rotationX);
}

void Rectangle::setWorldPosition(double x, double y)
{
	SimpleShape::setWorldPosition(x, y);
	rectangle.setPosition(wTransform.position.X, wTransform.position.Y);
}

void Rectangle::setWorldRotation(double x)
{
	SimpleShape::setWorldRotation(x);
	rectangle.setRotation(wTransform.rotationX + rTransform.rotationX);
}

void Rectangle::draw(sf::RenderWindow * w)
{
	w->draw(rectangle);
}

void Rectangle::setLocalCoordinate(double aX, double aY)
{
	if (ownOrigin)
	{
		SimpleShape::setLocalCoordinate(aX, aY);
		rectangle.setOrigin(sf::Vector2f(length / 2.0, height / 2.0));
	}
	else if (ownOrigin == false)
		rectangle.setOrigin(sf::Vector2f(length / 2.0 - aX, height / 2.0 + aY));
	//SimpleShape::setLocalCoordinate(aX, aY);
	this->beginRotFromObject = MathFunction::vectorAngle(beginLocalCoordinateX + meshLocalPositionX, -beginLocalCoordinateY - meshLocalPositionY);
	if (this->beginRotFromObject > 270)
		this->minuendOfRot = 450;
	else if (this->beginRotFromObject > 90)
		this->minuendOfRot = 270;
	else 
		this->minuendOfRot = 90;
}
/////////////////////////////////////

Triangle::Triangle(double heightZ, double baseZ)
	:height(heightZ), base(baseZ) {}

void Triangle::draw(sf::RenderWindow *)
{
	std::cout << "-WIELOKAT (TROJKAT) NIEDOSTEPNY-\n";
}

void Triangle::setWorldPosition(double x, double y)
{
	SimpleShape::setWorldPosition(x, y);
	//rectangle.setPosition(worldCoordinateX, worldCoordinateY);
}