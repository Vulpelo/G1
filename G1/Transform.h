#pragma once

#ifndef POSITION_H
#define POSITION_H

#include "Position.h"

struct Transform
{
	Position position;
	double rotationX;
	double scaleX;
	double scaleY;

	Transform() : rotationX(0), scaleX(1), scaleY(1) {};
};

#endif // !POSITION_H
