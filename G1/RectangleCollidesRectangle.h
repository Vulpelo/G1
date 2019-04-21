#pragma once
#include "Collision.h"
#include "CollisionRectangle.h"

namespace G1 {

	class RectangleCollidesRectangle :
		public Collision
	{
	public:
		RectangleCollidesRectangle();
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~RectangleCollidesRectangle();
	};

}
