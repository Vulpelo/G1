#pragma once

#include "GameMap.h"
#include <iostream>
#include "GameObject001.h"

using namespace G1;

class Map001 : public GameMap
{
private:
	GameObject* player;
	double spawnEnemyTime;
	double actualSpawnEnemyTime;
public:
	Map001();
	void EventTick();
};