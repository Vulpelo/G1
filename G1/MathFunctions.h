#pragma once

#ifndef _MATH_FUNCTIONS_H_
#define _MATH_FUNCTIONS_H_

#include "MathVariables.h"
#include "Segment.h"

using namespace G1;

namespace GMath
{
	float twoPointsDistance(float X1, float Y1, float X2, float Y2);
	float twoPointsDistance(Vector2, Vector2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	float twoPointsAngle(float X1, float Y1, float X2, float Y2);
	/// <summary> Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
	/// Angle is measuring at first point </summary>
	float twoPointsAngle(Vector2, Vector2);

	float vectorAngle(float x, float y);

	/// <summary>
	/// New vector's direction is equal to segment direction
	/// </summary>
	Vector2 orthogonalProjectionPointOnLine(const Vector2& point, const Segment& ab);
};

#endif // !_MATH_FUNCTIONS_H_
