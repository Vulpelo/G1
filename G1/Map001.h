#pragma once

#include "GameMap.h"
#include "Mesh.h"

class Map001 : public GameMap
{
private:
	Object* player;
	double spawnEnemyTime;
	double actualSpawnEnemyTime;
public:
	Map001();
	void EventTick();
};