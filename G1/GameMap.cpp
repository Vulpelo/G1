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

	GameMap::~GameMap()
	{
		for (size_t i = 0; i < objects.size(); i++) {
			delete objects[i];
		}
		objects.clear();
	}

	std::vector<GameObject*> GameMap::getAllObjects()
	{
		return objects;
	}

	GameObject * GameMap::findGameObjectByTag(const std::string & tag)
	{
		for each (GameObject* go in objects) {
			if (go->isTag(tag))
				return go;
		}
		return NULL;
	}

	void GameMap::mainStartPlay()
	{
		startPlay();
		for each (GameObject* go in objects) {
			go->mainStartPlay();
		}
	}

	void GameMap::mainBeginPlay()
	{
		beginPlay();
		for each (GameObject* go in objects) {
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
				objects.at(i-1)->mainFixedEventTick();
		}
		/* executing fixedEventTick before EventTIck */
		//for (unsigned int i = 0; i < objects.size(); i++) {
		//}
		for (unsigned int i = 0; i < objects.size(); i++) {
			objects.at(i)->mainEventTickComponents();
		}
		for (unsigned int i = 0; i < objects.size(); i++) {
			objects.at(i)->mainEventTick();
		}
		// TODO: child setting position later

		/*---Sorting gameObjects by sorting layer---*/
		auto forSorting = GameObjectsData::getAndClearToSortingLayer();
		if (!forSorting.empty()) {
			for (unsigned int i = 0; i < forSorting.size(); i++) {
				for (unsigned int j = 0; j < objects.size(); j++) {
					if (forSorting[i] == objects[j]) {
						objects.erase(objects.begin() + j, objects.begin() + j + 1);
						insertGameObjectBySortingLayer(forSorting[i]);
					}
				}
			}
		}

		/*--Spawning new actors--*/
		auto spawnables = GameObjectsData::getInstantiates();
		if (!spawnables->empty()) {
			for (size_t i = 0; i < spawnables->size(); i++) {
				dynamic_cast <GameObject*>(spawnables->operator[](i))->mainStartPlay();
			}
			while (!spawnables->empty())
			{
				if (GameObject* act = dynamic_cast <GameObject*>(spawnables->back()))
				{
					insertGameObjectBySortingLayer(act);
					act->mainBeginPlay();
					spawnables->pop_back();
				}
			}
		}

		this->eventTick();
	}

}
