#include "MathFunctions.h"

namespace GMath 
{
	float twoPointsDistance(float X1, float Y1, float X2, float Y2)
	{
		float x = X1 - X2;
		float y = Y1 - Y2;
		x *= x;
		y *= y;

		return sqrtf(x + y);
	}

	float twoPointsDistance(Vector2 cor1, Vector2 cor2)
	{
		float x = cor1.x - cor2.x;
		float y = cor1.y - cor2.y;
		x *= x;
		y *= y;

		return sqrtf(x + y);
	}

	float twoPointsAngle(float X1, float Y1, float X2, float Y2)
	{
		float value = (180 * atanf((X1 - X2) / (Y1 - Y2))) / float(M_PI);
		if (Y1 >= Y2)
			value += 180;
		if (X1 > X2 && Y1 < Y2)
			value += 360;
		return value;
	}
	float twoPointsAngle(Vector2 cor1, Vector2 cor2)
	{
		float value;
		value = (180 * atanf((cor1.x - cor2.x) / (cor1.y - cor2.y))) / float(M_PI);
		if (cor1.y < cor2.y)
			value += 180;
		if (cor1.x < cor2.x && cor1.y >= cor2.y)
			value += 360;
		return value;
	}

	float vectorAngle(float x, float y)
	{
		float value;
		value = (180 * atanf(x / y)) / float(M_PI);
		if (y < 0)
			value += 180;
		if (x < 0 && y >= 0)
			value += 360;
		return value;
	}

	Vector2 orthogonalProjectionPointOnLine(const Vector2& point, const Segment& ab) {
		if (ab.getPoint1() == ab.getPoint2()) {
			return point;
		}

		return ab.getPoint1() + 
			(( ab.getPoint2()) - ab.getPoint1()) *
			(
				((point - ab.getPoint1()) * (ab.getPoint2() - ab.getPoint1())) 
				/
				(ab.getPoint1() - ab.getPoint2()).lengthNoSqrt()
			) ;
	}

	float shortestDistancePointToSegment(const Vector2& point, const Segment& ab) {
		// TODO: optimise
		return (orthogonalProjectionPointOnLine(point, ab) - point).length();
	}

}
