#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Vector2.h"

struct Transform
{
	Vector2 position;
	float rotationX = 0.0f;
	Vector2 scale = Vector2(1,1);

	Transform() {};

	Transform(float x, float y, float rot) 
		: position(Vector2(x,y)), rotationX(rot), scale(Vector2(1, 1)) {}

	Transform(const Vector2& position, const Vector2& scale = Vector2(1, 1), float rotationX = 0) 
		: position(position), rotationX(rotationX), scale(scale) {}

	Transform(const Vector2& position, float rotationX) 
		: position(position), rotationX(rotationX) {}
};

#endif // !_TRANSFORM_H_
