#pragma once

#ifndef _Object_H_
#define _Object_H_

#include "ControlInput.h"
#include "Vector2D.h"
#include "Layer.h"
#include "Transform.h"

// containers
#include <vector>
#include <set>

class Object
{
	friend class GameMap;
	friend class PhysicsHandle;

	Object* parent;

	// Displays object's components on screen
	virtual void render(sf::RenderWindow * w) = 0;
	virtual void mainBeginPlay();

protected:
#pragma region protected Variables

	// World transform
	Transform transform;

	//Mesh/Components
#pragma endregion
	virtual void mainEventTick(sf::Time deltaTime);

public:
	Object();
	Object(Transform nWTransform);
	
	void setParent(Object* parent);

	virtual ~Object();

	/// <summary>Function played at the begining when object is created</summary>
	virtual void beginPlay() = 0;

	/// <summary>Function if played every frame of object life span</summary>
	virtual void EventTick() = 0;

#pragma region set/get functions
	/// <summary> Returns copy of world Transform of this object in world space</summary>
	Transform get_wTransform();

	/// <summary> Sets world Transform of this object in world space</summary>
	void set_wTransform(Transform);

	/// <summary>Sets rotation of an object in world wide</summary>
	void setWorldRotation(double x);
#pragma endregion
};

#endif // !_Object_H_
