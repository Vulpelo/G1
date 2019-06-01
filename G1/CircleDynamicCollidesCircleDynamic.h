#pragma once

#ifndef _CIRCLE_DYNAMIC_COLLIDES_CIRCLE_DYNAMIC_H_
#define _CIRCLE_DYNAMIC_COLLIDES_CIRCLE_DYNAMIC_H_

#include "CircleCollider.h"

namespace G1 {

	class CircleDynamicCollidesCircleDynamic
	{
		friend class CircleCollidesCircle;

		void calculate(CircleCollider* circleCollider1, Vector2 velocity1, CircleCollider* circleCollider2, Vector2 velocity2);
	};

}

#endif //!_CIRCLE_DYNAMIC_COLLIDES_CIRCLE_DYNAMIC_H_
