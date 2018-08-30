#include "Physics.h"

bool Physics::raycast(Position origin, Vector2D direction, float maxDistance, Layer layerMask)
{
	// checking collision
	//for each (Object *object in mapObjects)
	//{
	//}
	PhysicsHandle::overlapsPoint(Position(2,3));

	return false;
}

std::vector<Object*>* Physics::circleColider(Transform pos, float radious)
{
	auto * overlapingObjects = PhysicsHandle::overlapsCollider(new CollisionCircle(radious, pos.position.X, pos.position.Y));
	return overlapingObjects;
}
