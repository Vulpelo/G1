#pragma once

#ifndef _CIRCLE_COLLIDES_CIRCLE_H_
#define _CIRCLE_COLLIDES_CIRCLE_H_

#include "Collision.h"
#include "CircleCollider.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "CircleDynamicCollidesCircleStatic.h"
#include "CircleDynamicCollidesCircleDynamic.h"

namespace G1 {

	class CircleCollidesCircle : public Collision
	{
		CircleDynamicCollidesCircleStatic cirDynCirStat;
		CircleDynamicCollidesCircleDynamic cirDynCirDyn;
	public:
		CircleCollidesCircle();
		CollisionCheck calculate(Collider* collider1, Collider* collider2);
		void calculate(CircleCollider* circleColliderDynamic, Vector2 velocityDynamic, CircleCollider* circleColliderStatic);
		~CircleCollidesCircle();
	};

}

#endif //!_CIRCLE_COLLIDES_CIRCLE_H_
