#include "MapManager.h"

namespace G1 {

	GameMap* MapManager::aMap = nullptr;

	void MapManager::loadMap(GameMap* nMap)
	{
		MapManager::aMap = nMap;
		MapManager::aMap->mainBeginPlay();
	}

	GameMap * MapManager::get_aMap()
	{
		return MapManager::aMap;
	}

	MapManager::~MapManager()
	{
	}

}
