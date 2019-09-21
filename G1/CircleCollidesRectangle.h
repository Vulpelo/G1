#pragma once

#ifndef CIRCLE_COLLIDES_RECTANGLE_H
#define CIRCLE_COLLIDES_RECTANGLE_H

#include "CircleCollidesCircle.h"
#include "RectangleCollidesRectangle.h"

namespace G1 {
	class CircleCollidesRectangle : public Collision
	{

	public:
		CollisionCheck calculate(Collider* collider1, Collider* collider2);


	};
}

#endif // !CIRCLE_COLLIDES_RECTANGLE_H
