#pragma once

#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include "GameMap.h"

namespace G1 {

	class MapManager
	{
		static GameMap* aMap;

	public:
		static void loadMap(GameMap*);
		static GameMap* get_aMap();
		~MapManager();
	};

}

#endif // !MAP_MANAGER_H
