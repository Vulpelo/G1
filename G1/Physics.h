#pragma once

#include "Position.h"
#include "Vector2D.h"
#include "Layer.h"
#include "Properties.h"
#include <vector>

class Physics {
	static bool raycast(Position origin, Vector2D direction, float maxDistance = INFINITY, Layer layerMask = Layer::DEFAULT);
};
