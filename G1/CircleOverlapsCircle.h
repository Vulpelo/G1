#pragma once

#ifndef _CIRCLE_OVERLAPS_CIRCLE_H_
#define _CIRCLE_OVERLAPS_CIRCLE_H_

#include "Overlapping.h"
#include "CircleCollider.h"

namespace G1 {

	class CircleOverlapsCircle :
		public Overlapping
	{
	public:
		CircleOverlapsCircle();
		OverlappingCheck checkCollision(Collider* collider1, Collider* collider2);
		OverlappingCheck isColliding(Collider* collider1, Collider* collider2);
		~CircleOverlapsCircle();
	};

}

#endif // !_CIRCLE_OVERLAPS_CIRCLE_H_
