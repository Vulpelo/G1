#pragma once

/*
TEST MAP

player - GameObject001

KEY BINDINGS:
	arrow keys - move player around
	Q and E - rotate player
	S - switch player color
	SPACE - spawn at the player's position another GameObject

*/

#include "GameMap.h"
#include <iostream>
#include "GameObject001.h"
#include "GameObject003_wall.h"
#include "GameObject004_CircleWall.h"

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
