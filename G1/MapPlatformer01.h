#pragma once

#include "GameMap.h"
#include "Ground01.h"
#include "PlatformerPlayer.h"
#include "Eagle.h"
#include "Gem.h"
#include "Background.h"
#include "MapTile1.h"
#include "MapTile9.h"
#include "MapTileLadder.h"
#include "MyUI.h"
#include "GameMaster.h"

#include "MapLoader.h"

#include "GameObject004_CircleWall.h"
//#include "MapAssetsXmlParser.h"

using namespace G1;

class MapPlatformer01 :
	public GameMap
{
public:
	MapPlatformer01();
	void beginPlay() {};
	void eventTick() {};
};

