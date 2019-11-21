#pragma once

#ifndef _PREFAB_GAME_OBJECTS_H_
#define _PREFAB_GAME_OBJECTS_H_


#include "PlatformerPlayer.h"
#include "Background.h"

namespace G1 {

	class PrefabGameObjects {
	public:
		GameObject* getInstanceOf(const std::string& prefabName) {
			if (prefabName == "PlatformerPlayer") {
				return new PlatformerPlayer();
			}
			if (prefabName == "Background") {
				return new Background();
			}
			return new GameObject();
		}
	};

}

#endif // !_PREFAB_GAME_OBJECTS_H_
