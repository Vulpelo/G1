#pragma once
#include "Collision.h"
#include "CollisionRectangle.h"
#include "CollisionCircle.h"

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
