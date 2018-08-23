#include "PhysicsHandle.h"

void PhysicsHandle::overlapDetectionUpdate(std::vector<Object*>& objects)
{
	/*---Checking collisions---*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < objects.size(); j++)
			if (PhysicsHandle::overlapsAnyComponent(objects.at(i)->getComponents(), objects.at(j)->getComponents()))
			{
				// adding to object vectors to object that are overlaping
				objects.at(i)->addNewOverlapingObject(objects.at(j));
				objects.at(j)->addNewOverlapingObject(objects.at(i));
			}
		/*---Update data in Object about overlaping objects---*/
		overlapingEndMain(objects[i]);
	}
}

bool PhysicsHandle::overlapsAnyComponent(std::vector <Component*> &components, std::vector <Component*> &otherComponents)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		for (unsigned int j = 0; j < otherComponents.size(); j++)
		{
			if (components[i]->getCollider() != NULL && otherComponents[j]->getCollider() != NULL)
				if (components[i]->collides(otherComponents[j]->getCollider()))
					return true;
		}
	}
	return false;
}

bool PhysicsHandle::overlapsComponentsUpdate(std::vector <Component*> &components, std::vector <Component*> &otherComponents)
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


void PhysicsHandle::overlapingEndMain(Object* object)
{
	//for each (Component* comp in object->getComponents())
	//{
	//	comp->overlapingEndMain();
	//	for each (Component*overComp in comp->getStartOverlapingComp())
	//	{
	//		object->startOverlapingComponent(comp->getName(), overComp);
	//	}
	//	
	//	for each (Component*overComp in comp->getIsOverlapingComp())
	//	{
	//		object->isOverlapingComponent(comp->getName(), overComp);
	//	}
	//	for each (Component*overComp in comp->getEndOverlapingComp())
	//	{
	//		object->endOverlapingComponent(comp->getName(), overComp);
	//	}
	//}

	/*=Making events for Components, function called in Object with this component=*/
	// not used because of performance
	/*
	for each (Component* comp in object->getComponents())
	{
		for (int i = 0; i < comp->overlapingComponents.size(); i++)
		{
			bool overlaping = false;
			int j = 0;
			for (j = 0; j < comp->newOverlapingComponents.size(); j++)
			{
				if (comp->overlapingComponents.at(i) == comp->newOverlapingComponents.at(j))
				{
					//czyli isOverlaping
					overlaping = true;
					break;
				}
			}

			if (overlaping == false)
			{
				object->endOverlapingComponent(comp->getName(), comp->overlapingComponents.at(i));
				comp->overlapingComponents.erase(comp->overlapingComponents.begin() + i--);
			}
			else
			{
				object->isOverlapingComponent(comp->getName(), comp->overlapingComponents.at(i));
				if (!comp->newOverlapingComponents.empty())
					comp->newOverlapingComponents.erase(comp->newOverlapingComponents.begin() + j);
			}
		}
		for (int i = 0; i < comp->newOverlapingComponents.size(); i++)
		{
			object->startOverlapingComponent(comp->getName(), comp->newOverlapingComponents.at(i));
			comp->overlapingComponents.push_back(comp->newOverlapingComponents.at(i));
		}
		comp->newOverlapingComponents.clear();
	}

	*/

	/*== Making events for Object ==*/
	std::vector<Object*>& ovObj = object->getOverlapingObjects();
	std::vector<Object*>& nOvObj = object->getNewOverlapingObjects();

	for (int i = 0; i < ovObj.size(); i++)
	{
		bool overlaping = false;
		int j = 0;
		for (j = 0; j < nOvObj.size(); j++)
		{
			if (ovObj.at(i) == nOvObj.at(j))
			{
				//czyli isOverlaping
				overlaping = true;
				break;
			}
		}

		if (overlaping == false)
		{
			object->endOverlaping(ovObj.at(i));
			ovObj.erase(ovObj.begin() + i--);
		}
		else
		{
			object->isOverlaping(ovObj.at(i));
			if (!nOvObj.empty())
				nOvObj.erase(nOvObj.begin() + j);
		}
	}
	for (int i = 0; i < nOvObj.size(); i++)
	{
		object->startOverlaping(nOvObj.at(i));
		ovObj.push_back(nOvObj.at(i));
	}
	nOvObj.clear();
}
