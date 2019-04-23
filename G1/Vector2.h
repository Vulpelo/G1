#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include "MathVariables.h"

class Vector2
{
public:
	float X;
	float Y;

	Vector2();
	Vector2(const Vector2*);
	Vector2(float x, float y);
	Vector2(Vector2&);

	void setVector(Vector2);
	void setVector(float x, float y);
	void setVectorByAngleAndLength(float angle, float length);

	Vector2 operator -(const Vector2&) const;
	Vector2 operator +(const Vector2&) const;
	Vector2 operator *(const float&) const;

	/// <summary> Result is a scalar </summary>
	float operator *(const Vector2&) const;

	/// <summary>
	/// Direction of vector in witch is facing. Angle is 0 when vector is pointing straight up.
	/// Return's 0 also when x and y are equal 0.
	/// </summary>
	float angle() const;

	/// <summary>Distance between begining and end of the vector</summary>
	float length() const;

	/// <summary>Returns vector with length equal 1</summary>
	Vector2 normalize() const;

	Vector2 invertX() const;
	Vector2 invertY() const;
	Vector2 invert() const;
};

#endif // !_VECTOR2_H_
