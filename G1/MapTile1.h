#pragma once

#include "MapTile.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "IPrefab.h"


class MapTile1 : public MapTile {
	G1::Sprite sprite;
	Vector2 initialImageSize;

	void updateScale();

public:
	MapTile1() {};
	MapTile1(const prefabArgs& args);
	MapTile1(const G1::Sprite& sprite, int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1); 

	void set(int x, int y, unsigned int xSpan = 1, unsigned int ySpan = 1);
	void startPlay();
	virtual void beginPlayCon() {};
};

