#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2.h"

struct Transform
{
	Vector2 position;
	double rotationX;
	double scaleX;
	double scaleY;

	Transform() : rotationX(0), scaleX(1), scaleY(1) {};
	Transform(float x, float y, float rot) : position(Vector2(x,y)), rotationX(rot), scaleX(1), scaleY(1) {}
	Transform(Position pos) : position(pos), rotationX(0), scaleX(1), scaleY(1) {}
	Transform(Vector2& vec) : position(vec), rotationX(0), scaleX(1), scaleY(1) {}
};

#endif // !TRANSFORM_H
