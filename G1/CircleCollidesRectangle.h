#pragma once

#ifndef _CIRCLE_COLLIDES_RECTANGLE_H_
#define _CIRCLE_COLLIDES_RECTANGLE_H_

#include "Collision.h"
#include "RectangleCollider.h"
#include "CircleCollider.h"

namespace G1 {

	class CircleCollidesRectangle :
		public Collision
	{
	public:
		CircleCollidesRectangle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleCollidesRectangle();
	};

}

#endif // !_CIRCLE_COLLIDES_RECTANGLE_H_
