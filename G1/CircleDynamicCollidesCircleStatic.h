#pragma once

#ifndef _CIRCLE_DYNAMIC_COLLIDES_CIRCLE_STATIC_H_
#define _CIRCLE_DYNAMIC_COLLIDES_CIRCLE_STATIC_H_

#include "CircleCollider.h"

namespace G1 {

	class CircleDynamicCollidesCircleStatic
	{
		friend class CircleCollidesCircle;

		CircleDynamicCollidesCircleStatic();
		void calculate(CircleCollider* circleColliderDynamic, const Vector2& velocityDynamic, CircleCollider* circleColliderStatic);
	};

}

#endif //!_CIRCLE_DYNAMIC_COLLIDES_CIRCLE_STATIC_H_
