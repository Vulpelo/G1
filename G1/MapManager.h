#pragma once

#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "GameMap.h"

class MapManager
{
	static GameMap* aMap;

public:
	static void loadMap(GameMap*);
	static GameMap* get_aMap();
	~MapManager();
};

#endif // !MAPMANAGER_H
