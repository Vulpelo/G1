#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Vector2.h"

struct Transform
{
	Vector2 position;
	float rotationX;
	float scaleX;
	float scaleY;

	Transform() : rotationX(0), scaleX(1), scaleY(1) {};
	Transform(float x, float y, float rot) : position(Vector2(x,y)), rotationX(rot), scaleX(1), scaleY(1) {}
	Transform(Position pos) : position(pos), rotationX(0), scaleX(1), scaleY(1) {}
	Transform(Position pos, float rotationX) : position(pos), rotationX(rotationX), scaleX(1), scaleY(1) {}
	Transform(Vector2& vec) : position(vec), rotationX(0), scaleX(1), scaleY(1) {}
	Transform(Vector2 pos, float rotationX) : position(pos), rotationX(rotationX), scaleX(1), scaleY(1) {}
};

#endif // !_TRANSFORM_H_
