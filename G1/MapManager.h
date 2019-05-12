#pragma once

#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

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

#endif // !_MAP_MANAGER_H_
