#pragma once

#ifndef _CIRCLE_OVERLAPS_RECTANGLE_H_
#define _CIRCLE_OVERLAPS_RECTANGLE_H_

#include "Collision.h"
#include "RectangleCollider.h"
#include "CircleCollider.h"

namespace G1 {

	class CircleOverlapsRectangle :
		public Collision
	{
	public:
		CircleOverlapsRectangle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleOverlapsRectangle();
	};

}

#endif // !_CIRCLE_OVERLAPS_RECTANGLE_H_
