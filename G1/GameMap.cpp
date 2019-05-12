#include "GameMap.h"


namespace G1 {
	void GameMap::insertGameObjectBySortingLayer(GameObject * gameObject)
	{
		for (unsigned int j = 0; j < objects.size(); j++) {
			if (gameObject->getSortingLayer() <= objects[j]->getSortingLayer()) {
				objects.insert(objects.begin() + j, gameObject);
				return;
			}
		}
		objects.push_back(gameObject);
	}

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

		/*---Sorting gameObjects by sorting layer---*/
		auto forSorting = GameObjectsData::toSortingLayer;
		if (!forSorting.empty()) {
			for (unsigned int i = 0; i < forSorting.size(); i++) {
				
				for (unsigned int j = 0; j < objects.size(); j++) {
					if (forSorting[i] == objects[j]) {
						objects.erase(objects.begin() + j, objects.begin() + j + 1);
					}
				}

				insertGameObjectBySortingLayer(forSorting[i]);
			}
		}

		/*--Spawning new actors--*/
		auto spawnables = GameObjectsData::getInstantiates();
		while (!spawnables->empty())
		{
			if (GameObject* act = dynamic_cast <GameObject*>(spawnables->back()))
			{
				insertGameObjectBySortingLayer(act);

				// this->objects.push_back(act);
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

}
