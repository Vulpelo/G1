#include "ExamplePlatformerGame.h"

void ExamplePlatformerGame::beginPlay()
{
	//[](std::string name) {
	//	if (name == "map1") {
	//		return (GameMap*)new MapPlatformer01();
	//	}
	//	if (name == "tilemap01") {
	//		return (GameMap*)new TileMap01();
	//	}
	//};
	MapManager::getInstance().setMapManageFunction([](std::string mapName) {
		if (mapName == "MainMenu") {
			return dynamic_cast<GameMap*>(new MapMainMenu());
		}
		if (mapName == "map1") {
			return dynamic_cast<GameMap*>( new MapPlatformer01() );
		}

		if (mapName == "tilemap01") {
			return dynamic_cast<GameMap*>(new TileMap01());
		}
		if (mapName == "testMap1") {
			return dynamic_cast<GameMap*>(new Map001());
		}
		if (mapName == "testMap2") {
			return dynamic_cast<GameMap*>(new Map002());
		}
		return dynamic_cast<GameMap*>(new DefaultGameMap());
	});

	MapManager::getInstance().loadMap("MainMenu");
//	MapManager::getInstance().loadMap("map1");
	//MapManager::getInstance().loadMap(new MapPlatformer01());


	//MapManager::getInstance().loadMap( MapPlatformer01() );
	//MapManager::getInstance().loadMap(Map001());
}
