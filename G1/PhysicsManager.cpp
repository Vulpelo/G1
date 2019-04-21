#include "PhysicsManager.h"

namespace G1 {

	PhysicsManager::PhysicsManager()
	{
	}

	void PhysicsManager::handle()
	{
		collisionDetection.checkCollisions();

		overlapingGameObjectsStates.manageStatesAndFireFunctions();
	}


	PhysicsManager::~PhysicsManager()
	{
	}

}
