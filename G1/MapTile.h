#pragma once

#include "GameObject.h"

#include "MapTileProperties.h"

class MapTile : public G1::GameObject {
protected:

	int x = 0;
	int y = 0;
	unsigned int xSpan = 1;
	unsigned int ySpan = 1;
	bool collision = false;

	virtual void updateScale() = 0;

public:
	MapTile() {};
	MapTile(int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1) :
		x(x), y(y), xSpan(xSpan), ySpan(ySpan), collision(collision) { setLayer(layer); };

	virtual void set(int x, int y, unsigned int xSpan = 1, unsigned int ySpan = 1) = 0;
};
