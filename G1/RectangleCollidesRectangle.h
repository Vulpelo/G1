#pragma once
#include "Collision.h"
#include "CollisionRectangle.h"

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
