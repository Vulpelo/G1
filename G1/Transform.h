#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Position.h"

struct Transform
{
	Position position;
	double rotationX;
	double scaleX;
	double scaleY;

	Transform() : rotationX(0), scaleX(1), scaleY(1) {};
};

#endif // !TRANSFORM_H
