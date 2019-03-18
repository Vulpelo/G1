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
			go->beginPlay();
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
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (GameObject* act = dynamic_cast <GameObject*>(objects.at(i)))
			{
				//std::vector <GameObject*> ac = act->toSpawn();
				//while (!ac.empty())
				//{
				//	this->objects.push_back(ac.back());
				//	ac.pop_back();
				//}
			}
		}

		this->eventTick();
	}

	void GameMap::eventTick()
	{
	}

	//void GameMap::render(sf::RenderWindow * w)
	//{
	//	for (unsigned int i = 0; i < objects.size(); i++)
	//		objects.at(i)->render(w);
	//}

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
