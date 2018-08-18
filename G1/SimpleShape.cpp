#include <iostream>
#include "SimpleShape.h"

SimpleShape::SimpleShape() 
	: ownOrigin(false) 
{
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
	if (begin_rTransform.position.X + meshLocalPositionX != 0 || begin_rTransform.position.Y + meshLocalPositionY != 0)
	{
		std::cout << this << "-RX " << wTransform.rotationX << "::X " << rTransform.position.X << ":Y " << rTransform.position.Y;
		this->begin_rTransform.rotationX = MathFunction::vectorAngle(begin_rTransform.position.X + meshLocalPositionX, -begin_rTransform.position.Y + meshLocalPositionY);

		//double begin_rTransform.rotationX = atan(rTransform.position.X / rTransform.position.Y * 180 * M_PI);
		double c = sqrt((begin_rTransform.position.X + meshLocalPositionX)*(begin_rTransform.position.X + meshLocalPositionX)
			+ (begin_rTransform.position.Y + meshLocalPositionY)*(begin_rTransform.position.Y + meshLocalPositionY));
		//rTransform.position.X = c * sin((worldRotationX - localRotationX + begin_rTransform.rotationX)*M_PI / 180);
		rTransform.position.X = c * sin((wTransform.rotationX + begin_rTransform.rotationX)*M_PI / 180);

		if (wTransform.rotationX >= minuendOfRot - begin_rTransform.rotationX && wTransform.rotationX <= minuendOfRot + 180 - begin_rTransform.rotationX)
		{
			rTransform.position.Y = sqrt(c*c - rTransform.position.X*rTransform.position.X);
			std::cout << "::CON1 : " << begin_rTransform.rotationX << ";90 " << 90 - begin_rTransform.rotationX << ";270 " << 270 - begin_rTransform.rotationX;
		}
		else
		{
			rTransform.position.Y = -sqrt(c*c - rTransform.position.X*rTransform.position.X);
			std::cout << "::CON2 : " << begin_rTransform.rotationX << ";90 " << 90 - begin_rTransform.rotationX << ";270 " << 270 - begin_rTransform.rotationX;
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
	this->begin_rTransform.position.X = aX;
	this->rTransform.position.Y = -aY - meshLocalPositionY;
	this->begin_rTransform.position.Y = -aY;
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

	//!! this->begin_rTransform.rotationX = MathFunction::vectorAngle(rTransform.position.X, -rTransform.position.Y);
	this->begin_rTransform.rotationX = MathFunction::vectorAngle(begin_rTransform.position.X + meshLocalPositionX, -begin_rTransform.position.Y - meshLocalPositionY);
	if (this->begin_rTransform.rotationX > 270)
		this->minuendOfRot = 450;
	else if (this->begin_rTransform.rotationX > 90)
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
	this->begin_rTransform.rotationX = MathFunction::vectorAngle(begin_rTransform.position.X + meshLocalPositionX, -begin_rTransform.position.Y - meshLocalPositionY);
	if (this->begin_rTransform.rotationX > 270)
		this->minuendOfRot = 450;
	else if (this->begin_rTransform.rotationX > 90)
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