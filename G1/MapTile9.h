#pragma once

#include "MapTile.h"
#include "Sprite.h"
#include "RectangleCollider.h"

class MapTile9 : public MapTile {
	struct SpriteTile {
		G1::Sprite sprite;
		Vector2 initialImageSize;
	} spriteTiles[9];

	void updateScale();

public:
	// Tiles: you want to ignore, specified in set(..)
	enum class SpriteTilePos {
		UL = 1, UM = 2, UR = 4,
		ML = 8, MM = 16, MR = 32,
		DL = 64, DM = 128, DR = 256
	};

	MapTile9() {};
	MapTile9(G1::Sprite tiles[9], int x, int y, bool collision = false, const Layer& layer = Layer::DEFAULT, unsigned int xSpan = 1, unsigned int ySpan = 1);

	/// <summary>
	/// Sets properties for tile. 
	/// Start position x,y (Y < 0 goes up)
	/// how much tiles should be filed in on x/y axis starting from x/y position
	/// If you want to ignore some textures that you dont want to draw. eq. SpriteTilePos::UM | SpriteTilePos::DM
	/// </summary>
	void set(int x, int y, unsigned int xSpan = 1, unsigned int ySpan = 1, int ignore = 0);
	void beginPlay();
};
