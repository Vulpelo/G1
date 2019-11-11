#pragma once

#ifndef _PHYSICS_MANAGER_H_
#define _PHYSICS_MANAGER_H_

#include "CollisionDetection.h"
#include "OverlapingGameObjectsStates.h"
#include "RigidbodyPhysics.h"

namespace G1 {

	class PhysicsManager
	{
		CollisionDetection collisionDetection;
		OverlapingGameObjectsStates overlapingGameObjectsStates;
		RigidbodyPhysics rigidbodyPhysics;

	public:
		PhysicsManager();
		void handle();
		~PhysicsManager();
	};

}

#endif // !_PHYSICS_MANAGER_H_
