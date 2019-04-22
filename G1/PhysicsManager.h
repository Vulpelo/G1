#pragma once

#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H


#include "CollisionDetection.h"
#include "OverlapingGameObjectsStates.h"

namespace G1 {

	class PhysicsManager
	{
		CollisionDetection collisionDetection;
		OverlapingGameObjectsStates overlapingGameObjectsStates;

	public:
		PhysicsManager();
		void handle();
		~PhysicsManager();
	};

}

#endif // !PHYSICS_MANAGER_H
