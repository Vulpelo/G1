#pragma once
#include "GameMap.h"
#include "Ground01.h"
#include "PlatformerPlayer.h"
#include "Background.h"
#include "MapTile1.h"
#include "MapTile9.h"

using namespace G1;

class MapPlatformer01 :
	public GameMap
{
public:
	MapPlatformer01();
	void beginPlay() {};
	void eventTick() {};
};

