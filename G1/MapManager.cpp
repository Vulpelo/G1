#include "MapManager.h"

GameMap* MapManager::aMap = nullptr;

void MapManager::loadMap(GameMap* nMap)
{
	MapManager::aMap = nMap;
}

GameMap * MapManager::get_aMap()
{
	return MapManager::aMap;
}

MapManager::~MapManager()
{
}
