#pragma once

#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include "GameMap.h"

namespace G1 {

	class MapManager
	{
		GameMap aMap;

	public:
		static MapManager& getInstance() { static MapManager instance; return instance; }

		void loadMap(GameMap&&);
		GameMap& get_aMap();
	};

}

#endif // !_MAP_MANAGER_H_
