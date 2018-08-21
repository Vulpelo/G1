#include "GameMap.h"

GameMap::GameMap() { }

std::vector<Object*> GameMap::getAllObjects()
{
	return objects;
}

void GameMap::mainEventTick(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;

	/*---Destroing objects or do mainEventTick---*/
	for (unsigned int i = objects.size(); i > 0; i--)
	{
		if (objects.at(i-1)->shouldBeDestroyed())
			objects.erase(objects.begin() + (i-1));
		else
			objects.at(i-1)->mainEventTick(deltaTime);
	}

	/*---Checking collisions---*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < objects.size(); j++)
			if (PhysicsHandle::overlapsComponentsUpdate(objects.at(i)->getComponents(), objects.at(j)->getComponents()))
			{
				overlapingMain(objects.at(i), objects.at(j));
				overlapingMain(objects.at(j), objects.at(i));
			}
	}

	/*---Update data in Object about overlaping objects---*/
	for each (Object* obj in objects)
		overlapingEndMain(obj);


	/*--Spawning new actors--*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (Actor* act = dynamic_cast <Actor*>(objects.at(i)))
		{
			std::vector <Object*> ac = act->toSpawn();
			while (!ac.empty())
			{
				this->objects.push_back(ac.back());
				ac.pop_back();
			}
		}
	}
	this->EventTick();
}

void GameMap::render(sf::RenderWindow * w)
{
	for (unsigned int i = 0; i < objects.size(); i++)
		objects.at(i)->render(w);
}

void GameMap::setInput(ControlInput * input)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (Actor *ac = dynamic_cast <Actor*>(objects.at(i)))
		{
			if (ac->hasPlayerInput())
				ac->setPlayerInput(input);
		}
	}
}

// TODO: move it out
void GameMap::overlapingMain(Object* target, Object *overlaped)
{
	target->addNewOverlapingObject(overlaped);
}

// TODO: move it out
void GameMap::overlapingEndMain(Object* object)
{
	for each (Component* comp in object->getComponents())
	{
		comp->overlapingEndMain();
		for(int i=0; i < comp->getStartOverlapingComp().size(); i++)
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

//bool GameMap::isCollidingObjectM(Object* object, Object *otherObject) const
//{
//	std::vector <Component*> components = object->getComponents();
//	std::vector <Component*> otherComponents = otherObject->getComponents();
//
//	bool objectCollides = false;
//
//	for (unsigned int i = 0; i < otherComponents.size(); i++)
//	{
//		for (unsigned int j = 0; j < components.size(); j++)
//		{
//			if (otherComponents.at(i)->getCollider() != NULL && components.at(j)->getCollider() != NULL)
//				if (components.at(j)->collides(otherComponents.at(i)->getCollider()))
//					return true;//-  
//					/*{
//					components.at(j)->addOverlapComponent(otherComponents.at(i));
//					components.at(i)->addOverlapComponent(otherComponents.at(j));
//					objectCollides = true;
//					}*/
//
//					// TODO: Trzeba dorobic ogolne eventy dla kazdego mesha a nie dla calego objektu
//		}
//	}
//	return false;//-
//				 /*return objectCollides;*/
//}
