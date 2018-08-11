#include "MathFunctions.h"

double MathFunction::twoPointsDistance(double X1, double Y1, double X2, double Y2)
{
	double X = X1 - X2;
	double Y = Y1 - Y2;
	X *= X;
	Y *= Y;

	return sqrt(X + Y);
}

double MathFunction::twoPointsDistance(Coordinate cor1, Coordinate cor2)
{
	double X = cor1.X - cor2.Y;
	double Y = cor1.Y - cor2.Y;
	X *= X;
	Y *= Y;

	return sqrt(X + Y);
}

double MathFunction::twoPointsAngle(double X1, double Y1, double X2, double Y2)
{
	double value = (180 * atan((X1 - X2) / (Y1 - Y2))) / M_PI;
	if (Y1 >= Y2)
		value += 180;
	if (X1 > X2 && Y1 < Y2)
		value += 360;
	return value;
}
double MathFunction::twoPointsAngle(Coordinate cor1, Coordinate cor2)
{
	double value;
	value = (180 * atan((cor1.X - cor2.X) / (cor1.Y - cor2.Y))) / M_PI;
	if (cor1.Y < cor2.Y)
		value += 180;
	if (cor1.X < cor2.X && cor1.Y >= cor2.Y)
		value += 360;
	return value;
}

double MathFunction::vectorAngle(double X, double Y)
{
	double value;
	value = (180 * atan(X / Y)) / M_PI;
	if (Y < 0)
		value += 180;
	if (X < 0 && Y >= 0)
		value += 360;
	return value;
}


/*========Coordinates========*/

Coordinate::Coordinate(double x, double y)
	:X(x), Y(y) {}

