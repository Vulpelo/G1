#include "PhysicsHandle.h"



bool PhysicsHandle::overlapsAnyComponent(std::vector <Component*> &components, std::vector <Component*> &otherComponents)
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

void PhysicsHandle::overlapDetectionUpdate(std::vector<Object*>& objects)
{
	/*---Checking collisions---*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < objects.size(); j++)
			if (PhysicsHandle::overlapsComponentsUpdate(objects.at(i)->getComponents(), objects.at(j)->getComponents()))
			{
				// adding to object vectors to object that are overlaping
				objects.at(i)->addNewOverlapingObject(objects.at(j));
				objects.at(j)->addNewOverlapingObject(objects.at(i));
			}
	}

	/*---Update data in Object about overlaping objects---*/
	for each (Object* obj in objects)
		overlapingEndMain(obj);
}

void PhysicsHandle::overlapingEndMain(Object* object)
{
	for each (Component* comp in object->getComponents())
	{
		comp->overlapingEndMain();
		for (int i = 0; i < comp->getStartOverlapingComp().size(); i++)
		{
			object->startOverlapingComponent(comp->getName(), comp->getStartOverlapingComp()[i]);
		}
		for (int i = 0; i < comp->getIsOverlapingComp().size(); i++)
		{
			object->isOverlapingComponent(comp->getName(), comp->getIsOverlapingComp()[i]);
		}
		for (int i = 0; i < comp->getEndOverlapingComp().size(); i++)
		{
			object->endOverlapingComponent(comp->getName(), comp->getEndOverlapingComp()[i]);
		}
	}


	std::vector<Object*> ovObj = object->getOverlapingObjects();
	std::vector<Object*> nOvObj = object->getNewOverlapingObjects();


	for (int i = 0; i < ovObj.size(); i++)
	{
		bool overlaping = false;
		int j = 0;
		for (j = 0; j < object->getNewOverlapingObjects().size(); j++)
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
