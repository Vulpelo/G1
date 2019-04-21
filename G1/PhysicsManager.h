#pragma once
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