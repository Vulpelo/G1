#pragma once

#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "CollisionCheck.h"
#include "Collider.h"
#include "Rigidbody.h"

namespace G1 {

	class Collision
	{
		friend class CollisionCalculation;
		virtual CollisionCheck calculate(Collider* collider1, Collider* collider2) = 0;
		virtual void calculateVelocityDirection(GameObject* gameObject1, Rigidbody* rigidbody1, GameObject* gameObject2, Rigidbody* rigidbody2) {};
	};

}

#endif // !_COLLISION_H_
