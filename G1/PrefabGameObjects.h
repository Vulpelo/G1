#pragma once

#ifndef _PREFAB_GAME_OBJECTS_H_
#define _PREFAB_GAME_OBJECTS_H_

#include "PlatformerPlayer.h"
#include "MapTile9.h"
#include "MapTile1.h"
#include "Background.h"
#include "Gem.h"
#include "Oposum.h"
#include "IPrefab.h"

namespace G1 {

	class PrefabGameObjects {
	public:
		GameObject* getInstanceOf(const std::string& prefabName, const prefabArgs& args) {
			if (prefabName == "PlatformerPlayer") {
				return new PlatformerPlayer(); // TODO args
			}
			if (prefabName == "Background") {
				return new Background(args);
			}
			if (prefabName == "MapTile9") {
				return new MapTile9(args);
			}
			if (prefabName == "MapTile1") {
				return new MapTile1(args);
			}
			if (prefabName == "Gem") {
				return new Gem(); // TODO args
			}
			if (prefabName == "Oposum") {
				return new Oposum(); // TODO args
			}
			return NULL;
		}
	};

}

#endif // !_PREFAB_GAME_OBJECTS_H_
