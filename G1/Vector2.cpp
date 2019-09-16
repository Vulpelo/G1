#include "Vector2.h"


Vector2::Vector2()
	: x(0), y(0) {}

Vector2::Vector2(float x, float y)
	: x(x), y(y) {}

Vector2::Vector2(const Vector2 &vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

void Vector2::setVectorByAngleAndLength(float angle, float length)
{
	float s = angle * float(M_PI) / 180;
	this->x = length * sinf(s);
	this->y = length * cosf(s);
}

Vector2 Vector2::operator-(const Vector2 & other) const
{
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator+(const Vector2 & other) const
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 & Vector2::operator+=(const Vector2 & vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2 Vector2::operator*(const float & f)
{
	return Vector2(this->x * f, this->y * f);
}

float Vector2::operator*(const Vector2 & vector) const
{
	return this->x * vector.x + this->y * vector.y;
}

Vector2 operator*(const float & f, const Vector2 & vector)
{
	return Vector2(vector.x * f, vector.y * f);
}

float Vector2::angle() const
{
	float value = 0;
	if (y != 0) {
		value = (180 * atanf(x / y)) / float(M_PI);
		if (y < 0)
			value += 180;
		if (x < 0 && y >= 0)
			value += 360;
	}
	else if (x > 0)
		value = 90;
	else if (x < 0)
		value = 270;

	return value;
}

float Vector2::length() const
{
	return sqrtf(x*x + y*y);
}

float Vector2::lengthNoSqrt() const {
	return x*x + y*y;
}

Vector2 Vector2::normalize() const
{
	Vector2 nV;
	nV.x = this->x / this->length();
	nV.y = this->y / this->length();
	return nV;
}

Vector2 Vector2::invertX() const
{
	return Vector2(-x, y);
}

Vector2 Vector2::invertY() const
{
	return Vector2(x, -y);
}

Vector2 Vector2::invert() const
{
	return Vector2(-x, -y);
}

short Vector2::quadrant() const
{
	if (x < 0) {
		if (y < 0) {
			return 3;
		}
		else {
			return 2;
		}
	}
	else {
		if (y < 0) {
			return 4;
		}
		else {
			return 1;
		}
	}
}
