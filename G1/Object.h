#pragma once

#ifndef _Object_H_
#define _Object_H_

#include "Component.h"
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

	//collision interactions (interacts any of objects components)
	std::vector <Object *> overlapingObjects;
	std::vector <Object *> newOverlapingObjects;

	//Object distruct
	bool destroyObject;
	float currentLifeTime;
	float lifeTime;


	std::vector<Object*>& getOverlapingObjects();
	std::vector<Object*>& getNewOverlapingObjects();
	void addNewOverlapingObject(Object* overlaped);
	// Displays object's components on screen
	void render(sf::RenderWindow * w);
	virtual void mainBeginPlay();

protected:
#pragma region protected Variables
	std::set<Layer> layers;

	// World transform
	Transform wTransform;

	//Mesh/Components
	std::vector <Component*> components;
#pragma endregion
	virtual void mainEventTick(sf::Time deltaTime);
#pragma region Functions that are used only by engine
#pragma endregion
	void updateMesh();

public:
	Object();
	Object(Transform nWTransform);
	virtual ~Object();

	/// <summary>Function played at the begining when object is created</summary>
	virtual void beginPlay() = 0;

	/// <summary>Function if played every frame of object life span</summary>
	virtual void EventTick() = 0;

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
	void DestroyObject(float nlifeTime = 0.);

#pragma region set/get functions
	/// <summary> Returns copy of world Transform of this object in world space</summary>
	Transform get_wTransform();
	/// <summary> Sets world Transform of this object in world space</summary>
	void set_wTransform(Transform);

	/// <summary>Sets position of an object in world wide</summary>
	void setWorldCoordinate(double x, double y);

	/// <summary>Sets rotation of an object in world wide</summary>
	void setWorldRotation(double x);

	/// <summary>Return's reference to container with all Object's components</summary>
	std::vector <Component*> &getComponents();
#pragma endregion
};

#endif // !_Object_H_
