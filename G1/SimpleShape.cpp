#include <iostream>
#include "SimpleShape.h"

SimpleShape::SimpleShape() 
	: scaleX(1), scaleY(1), 
	localCoordinateX(0), localCoordinateY(0),
	worldCoordinateX(0), worldCoordinateY(0),
	localRotationX(0),
	worldRotationX(0),
	ownOrigin(false) 
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
	worldRotationX = x;
}

void SimpleShape::setWorldPosition(double x, double y)
{
	if (beginLocalCoordinateX + meshLocalPositionX != 0 || beginLocalCoordinateY + meshLocalPositionY != 0)
	{
		std::cout << this << "-RX " << worldRotationX << "::X " << localCoordinateX << ":Y " << localCoordinateY; 
		this->beginRotFromObject = MathFunction::vectorAngle(beginLocalCoordinateX + meshLocalPositionX, -beginLocalCoordinateY + meshLocalPositionY);

		//double beginRotFromObject = atan(localCoordinateX / localCoordinateY * 180 * M_PI);
		double c = sqrt((beginLocalCoordinateX + meshLocalPositionX)*(beginLocalCoordinateX + meshLocalPositionX)
			+ (beginLocalCoordinateY + meshLocalPositionY)*(beginLocalCoordinateY + meshLocalPositionY));
		//localCoordinateX = c * sin((worldRotationX - localRotationX + beginRotFromObject)*M_PI / 180);
		localCoordinateX = c * sin((worldRotationX + beginRotFromObject)*M_PI / 180);

		if (worldRotationX >= minuendOfRot - beginRotFromObject && worldRotationX <= minuendOfRot + 180 - beginRotFromObject)
		{
			localCoordinateY = sqrt(c*c - localCoordinateX*localCoordinateX);
			std::cout << "::CON1 : " << beginRotFromObject << ";90 " << 90 - beginRotFromObject << ";270 " << 270 - beginRotFromObject;
		}
		else
		{
			localCoordinateY = -sqrt(c*c - localCoordinateX*localCoordinateX);
			std::cout << "::CON2 : " << beginRotFromObject << ";90 " << 90 - beginRotFromObject << ";270 " << 270 - beginRotFromObject;
		}
		if (minuendOfRot == 270)
			localCoordinateY = -localCoordinateY;
		std::cout << std::endl;

	}
	worldCoordinateX = localCoordinateX + x;
	worldCoordinateY = localCoordinateY - y;

}

void SimpleShape::setScale(double sX, double sY)
{
	this->scaleX = sX;
	this->scaleY = sY;
}


void SimpleShape::setLocalCoordinate(double aX, double aY)
{
	this->localCoordinateX = aX + meshLocalPositionX;
	this->beginLocalCoordinateX = aX;
	this->localCoordinateY = -aY - meshLocalPositionY;
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
	return worldCoordinateX + localCoordinateX;
}

double SimpleShape::getYWorldPosition()
{
	return worldCoordinateY + localCoordinateY;
}

double SimpleShape::getXWorldRotation()
{
	return worldRotationX;
}
double SimpleShape::getXLocalRotation()
{
	return localRotationX;
}
void SimpleShape::setLocalRotation(double x)
{
	this->localRotationX = x;
}

/////////////////////////////////////

Circle::Circle(double radiusT, sf::Color c)
	:radius(radiusT),
	SimpleShape(c)
{

	circle.setOrigin(sf::Vector2f(radius, radius));
	circle.setRadius(radius);
	circle.setPosition(worldCoordinateX + localCoordinateX, worldCoordinateY + localCoordinateY);
	circle.setRotation(worldRotationX + localRotationX);
	circle.setFillColor(color);
}

void Circle::setWorldPosition(double x, double y)
{
	SimpleShape::setWorldPosition(x, y);

	circle.setPosition(worldCoordinateX, worldCoordinateY);
}

void Circle::setWorldRotation(double x)
{
	SimpleShape::setWorldRotation(x);
	circle.setRotation(worldRotationX + localRotationX);
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

	//!! this->beginRotFromObject = MathFunction::vectorAngle(localCoordinateX, -localCoordinateY);
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
	rectangle.setPosition(worldCoordinateX + localCoordinateX, worldCoordinateY + localCoordinateY);
	rectangle.setRotation(worldRotationX + localRotationX);
}

void Rectangle::setWorldPosition(double x, double y)
{
	SimpleShape::setWorldPosition(x, y);
	rectangle.setPosition(worldCoordinateX, worldCoordinateY);
}

void Rectangle::setWorldRotation(double x)
{
	SimpleShape::setWorldRotation(x);
	rectangle.setRotation(worldRotationX + localRotationX);
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