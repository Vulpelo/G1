#pragma once

#ifndef _CIRCLE_OVERLAPS_RECTANGLE_H_
#define _CIRCLE_OVERLAPS_RECTANGLE_H_

#include "Overlapping.h"
#include "RectangleCollider.h"
#include "CircleCollider.h"

namespace G1 {

	class CircleOverlapsRectangle :
		public Overlapping
	{
	public:
		CircleOverlapsRectangle();
		OverlappingCheck checkCollision(Collider* collider1, Collider* collider2);
		OverlappingCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleOverlapsRectangle();
	};

}

#endif // !_CIRCLE_OVERLAPS_RECTANGLE_H_
