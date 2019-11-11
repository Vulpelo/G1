#pragma once

#ifndef _COLLISION_CALCULATION_H_
#define _COLLISION_CALCULATION_H_

#include <vector>
#include "CollisionCheck.h"
#include "Collider.h"
#include "Collision.h"
#include "CircleCollidesCircle.h"
#include "CircleCollidesRectangle.h"
#include "RectangleCollidesRectangle.h"

namespace G1 {

	class CollisionCalculation
	{
		std::vector<Collision*> collisionTypes;
	public:
		CollisionCalculation();
		void doCalculation(Collider* collider1, Collider* collider2);
		~CollisionCalculation();
	};

}

#endif //!_COLLISION_CALCULATION_H_
