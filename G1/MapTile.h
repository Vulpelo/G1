#pragma once

#include "GameObject.h"

#include "MapTileProperties.h"
#include "IPrefab.h"

class MapTile : public G1::GameObject, public G1::IPrefab {
protected:

	int x = 0;
	int y = 0;
	unsigned int xSpan = 1;
	unsigned int ySpan = 1;
	bool collision = false;

	virtual void updateScale() = 0;

public:
	MapTile() {};
	MapTile(const G1::prefabArgs& args);
	MapTile(int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1) :
		x(x), y(y), xSpan(xSpan), ySpan(ySpan), collision(collision) { setLayer(layer); };
};
