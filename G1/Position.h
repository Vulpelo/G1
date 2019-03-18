#pragma once

#ifndef _Position_H_
#define _Position_H_

struct Position
{
public:
	float X;
	float Y;

	Position() : X(0), Y(0) {};
	Position(float x, float y) : X(x), Y(y) {};
};

#endif // !_Position_H_
