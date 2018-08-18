#include "Physics.h"

bool Physics::raycast(Position origin, Vector2D direction, float maxDistance, Layer layerMask)
{
	std::vector<Object*> mapObjects = Properties::get_aMap()->getAllObjects();

	// checking collision
	for each (Object *object in mapObjects)
	{
	}

	return false;
}
