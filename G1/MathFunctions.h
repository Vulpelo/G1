#pragma once
#include <math.h>
#include "Vector2D.h"
#include "Position.h"

#define M_PI 3.14159265358979323846

#ifndef _MathFunction_H_
#define _MathFunction_H_

class MathFunction
{
public:
	static double twoPointsDistance(double X1, double Y1, double X2, double Y2);
	static double twoPointsDistance(Position, Position);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	static double twoPointsAngle(double X1, double Y1, double X2, double Y2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	static double twoPointsAngle(Position, Position);

	static double vectorAngle(double X, double Y);
};

#endif // !_MathFunction_H_
