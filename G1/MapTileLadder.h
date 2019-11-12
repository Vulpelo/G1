#pragma once

#include "MapTile1.h"

class MapTileLadder : public MapTile1 {
public:
	MapTileLadder() {}
	MapTileLadder(int x, int y, const Layer& layer, unsigned int xSpan, unsigned int ySpan);

	void beginPlayCon();
};
