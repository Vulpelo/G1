#pragma once

#ifndef PHYSICS_H
#define PHYSICS_H

#include "Position.h"
#include "Vector2D.h"
#include "Layer.h"
#include "Component.h"
#include "Object.h"
#include <vector>
#include "Physics.h"

class PhysicsHandle {
	friend class Physics;
	friend class GameMap;

	static Object* overlapsPoint(Position pos) {
		return nullptr;
	}
	static bool overlapsComponents(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
	static bool overlapsComponentsUpdate(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
	static void a() {  }

};

#endif // !PHYSICS_H
