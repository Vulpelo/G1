#pragma once

#ifndef _Object_H_
#define _Object_H_

#include "Component.h"
//#include "Mesh.h"
#include "Collision.h"
#include "ControlInput.h"
#include "Vector2D.h"
#include "Layer.h"
#include "Transform.h"

// containers
#include <vector>
#include <set>

#include <iostream>

class Object
{
protected:
#pragma region Variables
	std::set<Layer> layers;

	//collision interactions (interacts any of objects components)
	std::vector <Object *> overlapingObjects;
	std::vector <Object *> newOverlapingObjects;

	// World transform
	Transform wTransform;
	//double worldCoordinateX, worldCoordinateY;
	double worldRotationX;

	//Object distruct
	bool destroyObject;
	double lifeTime;
	double currentLifeTime;

	//Mesh/Components
	std::vector <Component*> components;

#pragma endregion

#pragma region Protected Functions
	void updateMesh();
	virtual void mainBeginPlay();
#pragma endregion

public:
	Object();
	Object(double x, double y, double rotate);

	/// <summary>Function played at the begining when object is created</summary>
	virtual void beginPlay() = 0;

	/// <summary>Function if played every frame of object life span</summary>
	virtual void EventTick() = 0;

	//Mesh
	std::vector <Component*> getComponents() const;

#pragma region Functions that are used only by engine, but they need to be public
	//used by GameMap class
	void render(sf::RenderWindow * w);
	//used by GameMap class
	virtual bool isCollidingObjectM(Object *otherObject) const;
	//used by GameMap class
	void overlapingMain(Object *overlaped);
	//used by GameMap class
	void overlapingEndMain();
	//used in GameMap class
	virtual void mainEventTick(sf::Time deltaTime);
#pragma endregion

#pragma region Overlaping interactions
	/// <summary>Function is called every time when new object just touched this object</summary>
	virtual void startOverlaping(Object *overlaped) {};

	/// <summary>Function is called every time when some object is still coliding with this object</summary>
	virtual void isOverlaping(Object *overlaped) {};

	/// <summary>Function is called every time when some object is no longer coliding with this object</summary>
	virtual void endOverlaping(Object *overlaped) {};

	//chosen parts of this object are touching other parts of other object
	virtual void startOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
	virtual void isOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
	virtual void endOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
#pragma endregion

	/// <summary>Checks if object is going to be destroyed</summary>
	bool shouldBeDestroyed();
	/// <summary>Destroys object before next tick</summary>
	void DestroyObject();

#pragma region set functions
	/// <summary>Sets position of an object in world wide</summary>
	void setWorldCoordinate(double x, double y);

	/// <summary>Sets rotation of an object in world wide</summary>
	void setWorldRotation(double x);
#pragma endregion
};

#endif // !_Object_H_