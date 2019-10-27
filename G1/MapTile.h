#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "RectangleCollider.h"

class MapTile : public G1::GameObject {
	static Vector2 tileSize;

	G1::Sprite sprite;
	int x = 0;
	int y = 0;
	unsigned int xSpan = 1;
	unsigned int ySpan = 1;
	bool collision = false;

public:
	MapTile(const G1::Sprite& sprite, int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1); 
	void beginPlay();

	static void setTileSize(Vector2& ntileSize);
};

