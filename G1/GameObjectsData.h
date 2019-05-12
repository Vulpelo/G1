#pragma once

#ifndef _GAME_OBJECTS_DATA_H_
#define _GAME_OBJECTS_DATA_H_

#include "ISpawnable.h"

#include <vector>

namespace G1 {

	class GameObjectsData {
		friend class GameObject;
		friend class GameMap;
		friend class ISpawnable;

		static std::vector<ISpawnable*> toSpawn;
		static std::vector<GameObject*> toSortingLayer;

		static void addInstantiate(ISpawnable* spawnable);
		static std::vector<ISpawnable*>* getInstantiates();

		static void updateSortingLayer(GameObject* gameObject);
	};

}

#endif // !_GAME_OBJECTS_DATA_H_
