#include "Physics.h"

bool Physics::raycast(Position origin, Vector2D direction, float maxDistance, Layer layerMask)
{
	//std::vector<Object*> mapObjects = MapManager::get_aMap()->getAllObjects();

	// checking collision
	//for each (Object *object in mapObjects)
	//{
	//}

	return false;
}

bool Physics::overlapsComponents(std::vector <Component*> &components, std::vector <Component*> &otherComponents)
{
	for (unsigned int i = 0; i < otherComponents.size(); i++)
	{
		for (unsigned int j = 0; j < components.size(); j++)
		{
			if (otherComponents.at(i)->getCollider() != NULL && components.at(j)->getCollider() != NULL)
				if (components.at(j)->collides(otherComponents.at(i)->getCollider()))
					return true;//-  
						/*{
						components.at(j)->addOverlapComponent(otherComponents.at(i));
						components.at(i)->addOverlapComponent(otherComponents.at(j));
						objectCollides = true;
						}*/

						// TODO: Trzeba dorobic ogolne eventy dla kazdego mesha a nie dla calego objektu
		}
	}
	return false;
}

// TODO: Move out
bool Physics::overlapsComponentsUpdate(std::vector <Component*> &components, std::vector <Component*> &otherComponents)
{
	bool objectCollides = false;

	for (unsigned int i = 0; i < otherComponents.size(); i++)
	{
		for (unsigned int j = 0; j < components.size(); j++)
		{
			if (otherComponents.at(i)->getCollider() != NULL && components.at(j)->getCollider() != NULL)
				if (components.at(j)->collides(otherComponents.at(i)->getCollider())) {
					components.at(j)->addOverlapComponent(otherComponents.at(i));
					components.at(i)->addOverlapComponent(otherComponents.at(j));
					objectCollides = true;
					// TODO: Trzeba dorobic ogolne eventy dla kazdego mesha a nie dla calego objektu
				}
		}
	}
	return objectCollides;
}
