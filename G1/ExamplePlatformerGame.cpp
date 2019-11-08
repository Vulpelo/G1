#include "ExamplePlatformerGame.h"

void ExamplePlatformerGame::beginPlay()
{
	[](std::string name) {
		if (name == "map1") {
			return new MapPlatformer01();
		}
	};
	MapManager::getInstance().setMapManageFunction([](std::string mapName) {
		if (mapName == "map1") {
			return dynamic_cast<GameMap*>( new MapPlatformer01() );
		}
		return dynamic_cast<GameMap*>(new DefaultGameMap());
	});

	MapManager::getInstance().loadMap("map1");
	//MapManager::getInstance().loadMap(new MapPlatformer01());


	//MapManager::getInstance().loadMap( MapPlatformer01() );
	//MapManager::getInstance().loadMap(Map001());
}
