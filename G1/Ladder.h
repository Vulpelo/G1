#pragma once

#include "RectangleCollider.h"
#include "Sprite.h"
#include "GameObject.h"

#include "MapTileProperties.h"

using namespace G1;

class Ladder : public GameObject {
	unsigned int yLength = 1;

public:
	Ladder(unsigned yLength) : yLength(yLength) {};
	void beginPlay();
};
