#pragma once

#ifndef PHYSICS_H
#define PHYSICS_H

#include "Position.h"
#include "Vector2D.h"
#include "Layer.h"
#include "Component.h"
#include <vector>

class Physics {
public:
	static bool raycast(Position origin, Vector2D direction, float maxDistance = INFINITY, Layer layerMask = Layer::DEFAULT);
	static bool overlapsComponents(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
	
	static bool overlapsComponentsUpdate(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
};

#endif // !PHYSICS_H
