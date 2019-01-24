#pragma once

#include "Object.h"
#include "PhysicsHandle.h"
#include "Mesh.h"
#include <iostream>
#include "Component.h"

class GameObject : public Object
{
	virtual void mainBeginPlay();

	//collision interactions (interacts any of objects components)
	std::vector <Object *> overlapingObjects;
	std::vector <Object *> newOverlapingObjects;

	std::vector<Object*>& getOverlapingObjects();
	std::vector<Object*>& getNewOverlapingObjects();
	void addNewOverlapingObject(Object* overlaped);
	//Object distruct
	bool destroyObject;
	float currentLifeTime;
	float lifeTime;
protected:
	int layer;
	virtual void mainEventTick(sf::Time deltaTime);

	std::vector <Component*> components;
	virtual void updateMesh() = 0;

public:
	GameObject();
	GameObject(Transform nWTransform);

	void render(sf::RenderWindow * w);
	void updateMesh();

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

	/// <summary>Return's reference to container with all Object's components</summary>
	std::vector <Component*> &getComponents();

	/// <summary>Destroys object before next tick</summary>
	void DestroyObject(float nlifeTime = 0.);

	/// <summary>Checks if object is going to be destroyed</summary>
	bool shouldBeDestroyed();

	~GameObject();
};
