#pragma once

#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include "GameMap.h"
#include "DefaultGameMap.h"
#include "EventHandler.h"

namespace G1 {

	class MapManager
	{
		GameMap*(*manage)(std::string name) = [](std::string name) { return dynamic_cast<GameMap*>(new DefaultGameMap()); };

		GameMap* aMap = new DefaultGameMap();

		std::string actualMapName;
		std::string newMapName;

		void loadMapE();
		void reloadActualE();

	public:
		static MapManager& getInstance() { static MapManager instance; return instance; }
		/// <summary>
		/// Sets Function that creates new instances of maps depending on entered string. By default seted function returns DefaultGameMap()
		/// </summary>
		void setMapManageFunction(GameMap*(*manage)(std::string mapName)) { this->manage = manage; };

		/// <summary>
		/// Enter name of map that you want to load. Old map will get destroyed
		/// Map is loaded at the end of actual frame
		/// </summary>
		void loadMap(std::string name);
		/// <summary>
		/// Destroys and creates back new instance of the same map
		/// Map is reloaded at the end of actual frame
		/// </summary>
		void reloadActual();
		/// <summary>
		/// Returns actual playing map
		/// </summary>
		GameMap& get_aMap();
	};

}

#endif // !_MAP_MANAGER_H_
