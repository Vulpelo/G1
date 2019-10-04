#pragma once

#ifndef _RECTANGLE_COLLIDER_H_
#define _RECTANGLE_COLLIDER_H_

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class RectangleCollider : public Collider
	{
		float height, length;

	public:
		RectangleCollider(float length, float height, float posX = 0, float posY = 0, float rot = 0);
		bool isCollidingWith(Collider *otherCollider);
		Vector2 RectangleCollider::getFarthestPointVector();
	};

}

#endif // !_RECTANGLE_COLLIDER_H_
