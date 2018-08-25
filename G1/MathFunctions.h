#pragma once

#ifndef _MathFunction_H_
#define _MathFunction_H_

#include "MathVariables.h"
#include "Vector2D.h"

namespace GMath
{
	double twoPointsDistance(double X1, double Y1, double X2, double Y2);
	double twoPointsDistance(Position, Position);
	double twoPointsDistance(Vector2D, Vector2D);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	double twoPointsAngle(double X1, double Y1, double X2, double Y2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	double twoPointsAngle(Position, Position);

	double vectorAngle(double X, double Y);
};

#endif // !_MathFunction_H_
