#include "MathFunctions.h"

namespace GMath 
{
	float twoPointsDistance(float X1, float Y1, float X2, float Y2)
	{
		float X = X1 - X2;
		float Y = Y1 - Y2;
		X *= X;
		Y *= Y;

		return sqrtf(X + Y);
	}

	float twoPointsDistance(Position cor1, Position cor2)
	{
		float X = cor1.X - cor2.X;
		float Y = cor1.Y - cor2.Y;
		X *= X;
		Y *= Y;

		return sqrtf(X + Y);
	}

	float twoPointsDistance(Vector2 cor1, Vector2 cor2)
	{
		float X = cor1.X - cor2.X;
		float Y = cor1.Y - cor2.Y;
		X *= X;
		Y *= Y;

		return sqrtf(X + Y);
	}

	float twoPointsAngle(float X1, float Y1, float X2, float Y2)
	{
		float value = (180 * atanf((X1 - X2) / (Y1 - Y2))) / M_PI;
		if (Y1 >= Y2)
			value += 180;
		if (X1 > X2 && Y1 < Y2)
			value += 360;
		return value;
	}
	float twoPointsAngle(Position cor1, Position cor2)
	{
		float value;
		value = (180 * atanf((cor1.X - cor2.X) / (cor1.Y - cor2.Y))) / M_PI;
		if (cor1.Y < cor2.Y)
			value += 180;
		if (cor1.X < cor2.X && cor1.Y >= cor2.Y)
			value += 360;
		return value;
	}

	float vectorAngle(float X, float Y)
	{
		float value;
		value = (180 * atanf(X / Y)) / M_PI;
		if (Y < 0)
			value += 180;
		if (X < 0 && Y >= 0)
			value += 360;
		return value;
	}
}
