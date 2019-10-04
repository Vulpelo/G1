#include "PhysicsManager.h"

namespace G1 {

	PhysicsManager::PhysicsManager()
	{
	}

	void PhysicsManager::handle()
	{
		rigidbodyPhysics.applyForcesBeforeCollision();

		collisionDetection.checkCollisions();

		overlapingGameObjectsStates.manageStatesAndFireFunctions();
	}


	PhysicsManager::~PhysicsManager()
	{
	}

}
