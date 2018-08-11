#pragma once
#include <math.h>
#include "Vetor2D.h"
#define M_PI 3.14159265358979323846

#ifndef _Coordinate_H_
#define _Coordinate_H_

class Coordinate
{
public:
	double X;
	double Y;

	Coordinate(double x, double y);
};

#endif // !_Coordinate_H_

struct Transform
{
	Coordinate coordinates;
	double rotationX;
	double scaleX;
	double scaleY;
};


#ifndef _MathFunction_H_
#define _MathFunction_H_

class MathFunction
{
public:
	static double twoPointsDistance(double X1, double Y1, double X2, double Y2);
	static double twoPointsDistance(Coordinate, Coordinate);
	/*Angle 0 is on +y axis and is rising rotating to right. So on +x is 90 degree
		Angle is meseruing at first point */
	static double twoPointsAngle(double X1, double Y1, double X2, double Y2);
	static double twoPointsAngle(Coordinate, Coordinate);
	static double vectorAngle(double X, double Y);
};

#endif // !_MathFunction_H_