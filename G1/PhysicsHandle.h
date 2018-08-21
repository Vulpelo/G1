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
	/// <summary> Return's true as soon as any component from container, overlaps any component from another container</summary>
	static bool overlapsAnyComponent(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
	
	/// <summary>Goes thru whole containers to update each component with overlaping status.
	/// Return's true if any component from container, overlaps any component from another container.
	/// </summary>
	static void overlapDetectionUpdate(std::vector<Object*>&);
	static bool overlapsComponentsUpdate(std::vector <Component*> &components, std::vector <Component*> &otherComponents);
	static void overlapingEndMain(Object* object);
};

#endif // !PHYSICS_H
