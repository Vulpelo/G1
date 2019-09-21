#pragma once

#ifndef _RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_
#define _RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_

#include "RectangleCollider.h"
#include "Segment.h"

namespace G1 {

	class RectangleDynamicCollidesRectangleStatic
	{
		friend class RectangleCollidesRectangle;

		SideOfRectangle sideOfRectangle = SideOfRectangle::Undefined;
		
		RectangleDynamicCollidesRectangleStatic() {};
		void calculate(RectangleCollider* circleColliderDynamic, const Vector2& velocityDynamic, RectangleCollider* circleColliderStatic);
	};

}

#endif //!_RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_
