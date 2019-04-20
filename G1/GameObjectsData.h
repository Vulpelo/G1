#pragma once

#ifndef _GameObjectsData_H_
#define _GameObjectsData_H_

#include "ISpawnable.h"

#include <vector>

namespace G1 {

	class GameObjectsData {
		friend class GameObject;
		friend class GameMap;

		static std::vector<ISpawnable*> toSpawn;

		static void addInstantiate(ISpawnable* spawnable);
		static std::vector<ISpawnable*>* getInstantiates();
	};

}

#endif // !_GameObjectsData_H_
