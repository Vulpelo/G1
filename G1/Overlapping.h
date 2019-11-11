#pragma once

#ifndef _OVERLAPPING_H_
#define _OVERLAPPING_H_

#include "OverlappingCheck.h"
#include "Collider.h"

namespace G1 {

	class Overlapping {
		friend class CollisionDetection;
		virtual OverlappingCheck checkCollision(Collider* collider1, Collider* collider2) = 0;
		virtual OverlappingCheck isColliding(Collider* collider1, Collider* collider2) = 0;
	};

}

#endif // !_OVERLAPPING_H_
