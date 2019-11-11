#pragma once

#include "Vector2.h"

class MapTileProperties {
	static Vector2 tileSize;
	
public:
	static const Vector2& getTileSize();
	static void setTileSize(Vector2 & ntileSize);
};
