#include "Vector2.h"


Vector2::Vector2()
	: X(0), Y(0) {}

Vector2::Vector2(float x, float y)
	: X(x), Y(y) {}

Vector2::Vector2(Position pos)
{
	X = pos.X;
	Y = pos.Y;
}

Vector2::Vector2(Vector2 &vec)
{
	this->X = vec.X;
	this->Y = vec.Y;
}

Vector2::Vector2(const Vector2* vec)
	: X(vec->X), Y(vec->Y) {}

void Vector2::setVector(Vector2 vec)
{
	Vector2::Vector2(&vec);
}

void Vector2::setVector(float x, float y)
{
	this->X = x;
	this->Y = y;
}

void Vector2::setVectorByAngleAndLength(float angle, float length)
{
	double s = angle * M_PI / 180;
	this->X = length * sinf(s);
	this->Y = length * cosf(s);
}

Vector2 Vector2::operator-(const Vector2 & other) const
{
	return Vector2(this->X - other.X, this->Y - other.Y);
}

Vector2 Vector2::operator+(const Vector2 & other) const
{
	return Vector2(this->X + other.X, this->Y + other.Y);
}

Vector2 Vector2::operator*(const float &f) const
{
	return Vector2(this->X * f, this->Y * f);
}

float Vector2::operator*(const Vector2 &vec) const
{
	return this->X * vec.X + this->Y * vec.Y;
}

float Vector2::angle() const
{
	float value = 0;
	if (Y != 0) {
		value = (180 * atanf(X / Y)) / M_PI;
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

float Vector2::length() const
{
	return sqrtf(X*X + Y*Y);
}

Vector2 Vector2::normalize() const
{
	Vector2 nV;
	nV.X = this->X / this->length();
	nV.Y = this->Y / this->length();
	return nV;
}

Vector2 Vector2::invertX() const
{
	return Vector2(-X, Y);
}

Vector2 Vector2::invertY() const
{
	return Vector2(X, -Y);
}

Vector2 Vector2::invert() const
{
	return Vector2(-X, -Y);
}
