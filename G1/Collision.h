#pragma once

#include "CollisionCheck.h"
#include "Collider.h"

namespace G1 {

	class Collision {
		friend class CollisionDetection;
		virtual CollisionCheck isColliding(Collider* collider1, Collider* collider2) = 0;
	};

}
