#pragma once

#ifndef _Position_H_
#define _Position_H_

struct Position
{
public:
	double X;
	double Y;

	Position() : X(0), Y(0) {};
	Position(double x, double y) : X(x), Y(y) {};
};

#endif // !_Position_H_
