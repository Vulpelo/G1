#include "Vector2D.h"


Vector2D::Vector2D()
	: X(0), Y(0) {}

Vector2D::Vector2D(double x, double y)
	: X(x), Y(y) {}

Vector2D::Vector2D(Position pos)
{
	X = pos.X;
	Y = pos.Y;
}

Vector2D::Vector2D(Vector2D &vec)
{
	this->X = vec.X;
	this->Y = vec.Y;
}

Vector2D::Vector2D(const Vector2D* vec)
	: X(vec->X), Y(vec->Y) {}

void Vector2D::setVector(Vector2D vec)
{
	Vector2D::Vector2D(&vec);
}

void Vector2D::setVector(double x, double y)
{
	this->X = x;
	this->Y = y;
}

void Vector2D::setVectorByAngleAndLength(double angle, double length)
{
	double s = angle * M_PI / 180;
	this->X = length * sin(s);
	this->Y = length * cos(s);
}

Vector2D Vector2D::operator-(const Vector2D & other) const
{
	return Vector2D(this->X - other.X, this->Y - other.Y);
}

Vector2D Vector2D::operator+(const Vector2D & other) const
{
	return Vector2D(this->X + other.X, this->Y + other.Y);
}

Vector2D Vector2D::operator*(const float &f) const
{
	return Vector2D(this->X * f, this->Y * f);
}

double Vector2D::angle() const
{
	double value = 0;
	if (Y != 0) {
		value = (180 * atan(X / Y)) / M_PI;
		if (Y < 0)
			value += 180;
		if (X < 0 && Y >= 0)
			value += 360;
	}
	else if (X > 0)
		value = 90;
	else if (X < 0)
		value = 270;

	return value;
}

double Vector2D::length() const
{
	return sqrt(X*X + Y*Y);
}

Vector2D Vector2D::normalize() const
{
	Vector2D nV;
	nV.X = this->X / this->length();
	nV.Y = this->Y / this->length();
	return nV;
}
