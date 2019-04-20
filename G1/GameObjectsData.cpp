#include "GameObjectsData.h"

namespace G1 {

	std::vector<ISpawnable*> GameObjectsData::toSpawn;

	void GameObjectsData::addInstantiate(ISpawnable * spawnable)
	{
		toSpawn.push_back(spawnable);
	}

	std::vector<ISpawnable*>* GameObjectsData::getInstantiates()
	{
		return &toSpawn;
	}

}
