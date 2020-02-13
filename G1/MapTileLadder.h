#pragma once

#include "MapTile1.h"

class MapTileLadder : public MapTile1 {
public:
	MapTileLadder() {}
	MapTileLadder(const prefabArgs& args);
	MapTileLadder(int x, int y, unsigned int xSpan, unsigned int ySpan);

	void beginPlayCon();
};
