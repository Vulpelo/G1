#pragma once

#include "GameMap.h"
#include "MapLoader.h"

class TileMap01 : public G1::GameMap {
public:

	TileMap01() {};

	void startPlay() {
		MapLoader loader;
		loader.load(this, "./assets/maps_xml/map01.xml");
	}
};
