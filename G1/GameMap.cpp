#include "GameMap.h"


namespace G1 {

	GameMap::GameMap() {
	}

	std::vector<GameObject*> GameMap::getAllObjects()
	{
		return objects;
	}

	void GameMap::mainBeginPlay()
	{
		for each (GameObject* go in objects)
		{
			go->mainBeginPlay();
		}
	}


	void GameMap::mainEventTick()
	{
		/*---Destroing objects or do mainEventTick---*/
		for (unsigned int i = objects.size(); i > 0; i--)
		{
			if (objects.at(i - 1)->shouldBeDestroyed())
				objects.erase(objects.begin() + (i - 1));
			else
				objects.at(i - 1)->mainEventTick();
		}

		//--PhysicsHandle::overlapDetectionUpdate(objects);

		/*--Spawning new actors--*/
		auto spawnables = GameObjectsData::getInstantiates();
		while (!spawnables->empty())
		{
			if (GameObject* act = dynamic_cast <GameObject*>(spawnables->back()))
			{
				this->objects.push_back(act);
				act->mainBeginPlay();
				spawnables->pop_back();
			}
		}
		//--

		this->eventTick();
	}

	void GameMap::eventTick()
	{
	}

	void GameMap::setInput(ControlInput * input)
	{
		//for (unsigned int i = 0; i < objects.size(); i++)
		//{
		//	if (GameObject *ac = dynamic_cast <GameObject*>(objects.at(i)))
		//	{
		//		if (ac->hasPlayerInput())
		//			ac->setPlayerInput(input);
		//	}
		//}
	}

}
