#pragma once

#ifndef _RECTANGLE_OVERLAPS_RECTANGLE_H_
#define _RECTANGLE_OVERLAPS_RECTANGLE_H_

#include "Overlapping.h"
#include "RectangleCollider.h"

namespace G1 {

	class RectangleOverlapsRectangle :
		public Overlapping
	{
		bool check(Collider* rect1, Collider* rect2);
	public:
		RectangleOverlapsRectangle();
		OverlappingCheck checkCollision(Collider* collider1, Collider* collider2);
		OverlappingCheck isColliding(Collider* collider1, Collider* collider2);
		~RectangleOverlapsRectangle();
	};

}

#endif // !_RECTANGLE_OVERLAPS_RECTANGLE_H_
