#pragma once

#ifndef _CIRCLE_OVERLAPS_CIRCLE_H_
#define _CIRCLE_OVERLAPS_CIRCLE_H_

#include "Collision.h"
#include "CircleCollider.h"

namespace G1 {

	class CircleOverlapsCircle :
		public Collision
	{
	public:
		CircleOverlapsCircle();
		CollisionCheck checkCollision(Collider* collider1, Collider* collider2);
		CollisionCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleOverlapsCircle();
	};

}

#endif // !_CIRCLE_OVERLAPS_CIRCLE_H_
