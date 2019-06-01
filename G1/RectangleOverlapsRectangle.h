#pragma once

#ifndef _RECTANGLE_OVERLAPS_RECTANGLE_H_
#define _RECTANGLE_OVERLAPS_RECTANGLE_H_

#include "Collision.h"
#include "RectangleCollider.h"

namespace G1 {

	class RectangleOverlapsRectangle :
		public Collision
	{
		bool check(Collider* rect1, Collider* rect2);
	public:
		RectangleOverlapsRectangle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~RectangleOverlapsRectangle();
	};

}

#endif // !_RECTANGLE_OVERLAPS_RECTANGLE_H_
