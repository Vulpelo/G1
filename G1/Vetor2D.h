#pragma once
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

	/*==Morefuncs==*/

	/*Direction of vector in witch is facing.
	Angle is 0 when vector is straight up*/
	double angle();
	/*Distance between begining and end of the vector*/
	double length();
};