#pragma once

#ifndef _RECTANGLE_COLLIDES_RECTANGLE_H_
#define _RECTANGLE_COLLIDES_RECTANGLE_H_

#include "Collision.h"
#include "RectangleCollider.h"

namespace G1 {

	class RectangleCollidesRectangle :
		public Collision
	{
		bool check(Collider* rect1, Collider* rect2);
	public:
		RectangleCollidesRectangle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~RectangleCollidesRectangle();
	};

}

#endif // !_RECTANGLE_COLLIDES_RECTANGLE_H_
