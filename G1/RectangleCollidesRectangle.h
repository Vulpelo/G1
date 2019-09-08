#pragma once

#ifndef _RECTANGLE_COLLIDES_RECTANGLE_H
#define _RECTANGLE_COLLIDES_RECTANGLE_H

#include "Collision.h"
#include "CircleCollider.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleDynamicCollidesRectangleStatic.h"

namespace G1 {

	class RectangleCollidesRectangle : public Collision {
		
		RectangleDynamicCollidesRectangleStatic dynamicXStatic;
		//RectangleDynamicCollidesRectangleStatic recDynRecDyn;
	public:
		RectangleCollidesRectangle();
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		void calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2);
		~RectangleCollidesRectangle();
	};

}

#endif // !_RECTANGLE_COLLIDES_RECTANGLE_H
