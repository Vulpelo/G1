#pragma once
#include "Component.h"
//#include "Mesh.h"
#include "Collision.h"
#include "ControlInput.h"
#include "Vetor2D.h"
#include "Layer.h"

// containers
#include <vector>
#include <set>

#include <iostream>

#ifndef _Object_H_
#define _Object_H_

class Object
{
protected:
	std::set<Layer> layers;

	//collision interactions (interacts any of objects components)
	std::vector <Object *> overlapingObjects;
	std::vector <Object *> newOverlapingObjects;

	//Transform
	double worldCoordinateX, worldCoordinateY;
	double worldRotationX;

	//Object distruct
	bool destroyObject;
	double lifeTime;
	double currentLifeTime;

	//Mesh/Components
	std::vector <Component*> components;

	void updateMesh();
public:
	Object();
	Object(double x, double y, double rotate);
	virtual void beginPlay() = 0;
	virtual void mainBeginPlay();
	virtual void EventTick() = 0;
	virtual void mainEventTick(sf::Time deltaTime);
	void render(sf::RenderWindow * w);

	//Mesh
	std::vector <Component*> getComponents() const;

	/*-Overlaping interactions-*/
	virtual bool isCollidingObjectM(Object *otherObject) const;
	void overlapingMain(Object *overlaped);
	void overlapingEndMain();

	//This object is touching other object
	virtual void startOverlaping(Object *overlaped) {};
	virtual void isOverlaping(Object *overlaped) {};
	virtual void endOverlaping(Object *overlaped) {};

	//chosen parts of this object are touching other parts of other object
	virtual void startOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
	virtual void isOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
	virtual void endOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};


	//Object distruct
	bool shouldBeDestroyed();

	void setWorldCoordinate(double x, double y);
	void setWorldRotation(double x);
	void DestroyObject();
};

#endif // !_Object_H_