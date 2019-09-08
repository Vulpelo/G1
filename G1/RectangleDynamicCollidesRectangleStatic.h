#pragma once

#ifndef _RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_
#define _RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_

#include "RectangleCollider.h"
#include "Segment.h"

namespace G1 {

	enum class SideOfRectangle {
		Undefined = -1,
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};

	class RectangleDynamicCollidesRectangleStatic
	{
		friend class RectangleCollidesRectangle;

		SideOfRectangle sideOfRectangle = SideOfRectangle::Undefined;
		
		RectangleDynamicCollidesRectangleStatic() {};
		void calculate(RectangleCollider* circleColliderDynamic, const Vector2& velocityDynamic, RectangleCollider* circleColliderStatic);
	};

}

#endif //!_RECTANGLE_DYNAMIC_COLLIDES_RECTANGLE_STATIC_H_
