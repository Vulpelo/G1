#pragma once

#include "MapTile.h"
#include "Sprite.h"
#include "RectangleCollider.h"

class MapTile9 : public MapTile {
	// Tiles: Going from up left to down right UL, UM, UR, ML, MM, MR
	enum class SpriteTilePos {
		UL = 0, UM, UR, 
		ML, MM, MR, 
		DL, DM, DR
	};
	
	struct SpriteTile {
		G1::Sprite sprite;
		Vector2 initialImageSize;
	} spriteTiles[9];

	void updateScale();

public:
	MapTile9() {};
	MapTile9(G1::Sprite tiles[9], int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1);

	void set(int x, int y, unsigned int xSpan = 1, unsigned int ySpan = 1);
	void beginPlay();
};
