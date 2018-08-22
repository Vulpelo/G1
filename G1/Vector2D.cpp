#include "Vector2D.h"


Vector2D::Vector2D()
	: x(0), y(0) {}

Vector2D::Vector2D(double x, double y)
	: x(x), y(y) {}

Vector2D::Vector2D(Position pos)
{
	x = pos.X;
	y = pos.Y;
}

Vector2D::Vector2D(const Vector2D* vec)
	: x(vec->x), y(vec->y) {}

void Vector2D::setVector(Vector2D vec)
{
	Vector2D::Vector2D(&vec);
}

void Vector2D::setVector(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Vector2D::setVectorByAngleAndLength(double angle, double length)
{
	double s = angle * M_PI / 180;
	this->x = length * sin(s);
	this->y = length * cos(s);
}

Vector2D Vector2D::operator-(const Vector2D & other) const
{
	return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator+(const Vector2D & other) const
{
	return Vector2D(this->x + other.x, this->y+ other.y);
}

Vector2D Vector2D::operator*(const float &f) const
{
	return Vector2D(this->x * f, this->y * f);
}

double Vector2D::angle() const
{
	double value;
	value = (180 * atan(x / y)) / M_PI;
	if (y < 0)
		value += 180;
	if (x < 0 && y >= 0)
		value += 360;
	return value;
}

double Vector2D::length() const
{
	return sqrt(x*x + y*y);
}

Vector2D Vector2D::normalize() const
{
	Vector2D nV;
	nV.x = this->x / this->length();
	nV.y = this->y / this->length();
	return nV;
}
