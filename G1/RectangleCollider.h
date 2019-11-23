#pragma once

#ifndef _RECTANGLE_COLLIDER_H_
#define _RECTANGLE_COLLIDER_H_

#include "Collider.h"
#include "SimpleShape.h"

namespace G1 {

	class RectangleCollider : public Collider
	{
		float height = 10.f, length = 10.f;

	public:
		RectangleCollider() {
			this->collisionType = 'r';
		}
		RectangleCollider(float length, float height, float posX = 0, float posY = 0, float rot = 0);
		void setSize(float height, float length);
		bool isCollidingWith(Collider *otherCollider);
		Vector2 RectangleCollider::getFarthestPointVector();
	};

}

#endif // !_RECTANGLE_COLLIDER_H_
