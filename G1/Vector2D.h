#pragma once

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "MathFunctions.h"

class Vector2D
{
public:
	double x;
	double y;

	Vector2D();
	Vector2D(const Vector2D*);
	Vector2D(double x, double y);

	void setVector(Vector2D);
	void setVector(double x, double y);
	void setVectorByAngleAndLength(double angle, double length);

	/// <summary>
	/// Direction of vector in witch is facing. Angle is 0 when vector is pointing straight up.
	/// </summary>
	double angle() const; 

	/// <summary>Distance between begining and end of the vector</summary>
	double length() const;

	/// <summary>Returns vector with length equal 1</summary>
	Vector2D normalize() const;
};

#endif // !VECTOR2D_H
