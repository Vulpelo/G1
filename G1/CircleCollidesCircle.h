#pragma once

#ifndef _CIRCLE_COLLIDES_CIRCLE_H_
#define _CIRCLE_COLLIDES_CIRCLE_H_

#include "Collision.h"
#include "CircleCollider.h"

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

#endif // !_CIRCLE_COLLIDES_CIRCLE_H_
