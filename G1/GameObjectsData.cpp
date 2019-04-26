#include "GameObjectsData.h"

namespace G1 {

	std::vector<ISpawnable*> GameObjectsData::toSpawn;

	std::vector<GameObject*> GameObjectsData::toSortingLayer;

	void GameObjectsData::addInstantiate(ISpawnable * spawnable)
	{
		toSpawn.push_back(spawnable);
	}

	std::vector<ISpawnable*>* GameObjectsData::getInstantiates()
	{
		return &toSpawn;
	}

	void GameObjectsData::updateSortingLayer(GameObject * gameObject)
	{
		ISpawnable* spawnable = (ISpawnable*)gameObject;
		if (spawnable) {
			for (unsigned int i = 0; i < toSpawn.size(); i++) { //check if object is also about to spawn
				if (toSpawn[i] == spawnable) {
					return; // then there is no need to additionaly sort GameObject
				}
			}
		}

		toSortingLayer.push_back(gameObject);
	}

}
