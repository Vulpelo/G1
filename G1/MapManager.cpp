#include "MapManager.h"

namespace G1 {

	void MapManager::reloadActual()
	{
		newMapName = actualMapName;
		EventHandler::fireEvent([]() {
			MapManager::getInstance().reloadActualE();
		});
	}

	void MapManager::reloadActualE()
	{
		delete aMap;
		aMap = NULL;

		loadMapE();
	}

	void MapManager::loadMap(std::string name)
	{
		newMapName = name;
		EventHandler::fireEvent([]() {
			MapManager::getInstance().loadMapE();
		});
	}

	void MapManager::loadMapE()
	{
		aMap = manage(newMapName);
		actualMapName = newMapName;
		aMap->mainStartPlay();
		aMap->mainBeginPlay();
	}


	GameMap& MapManager::get_aMap()
	{
		return *aMap;
	}

}
