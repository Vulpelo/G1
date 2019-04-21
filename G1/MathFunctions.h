#pragma once

#ifndef _MathFunction_H_
#define _MathFunction_H_

#include "MathVariables.h"
#include "Vector2.h"

namespace GMath
{
	float twoPointsDistance(float X1, float Y1, float X2, float Y2);
	float twoPointsDistance(Position, Position);
	float twoPointsDistance(Vector2, Vector2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	float twoPointsAngle(float X1, float Y1, float X2, float Y2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	float twoPointsAngle(Position, Position);

	float vectorAngle(float X, float Y);
};

#endif // !_MathFunction_H_
