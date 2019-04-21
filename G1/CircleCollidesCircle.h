#pragma once
#include "Collision.h"
#include "CollisionCircle.h"

namespace G1 {

	class CircleCollidesCircle :
		public Collision
	{
	public:
		CircleCollidesCircle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleCollidesCircle();
	};

}
