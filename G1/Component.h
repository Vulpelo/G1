#pragma once

#ifndef _Component_H_
#define _Component_H_

#include "SimpleShape.h"
#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Collision.h"

class Component
{
	friend class PhysicsHandle;
	std::vector <Component *> newOverlapingComponents;

protected:
	//overlaping
	//std::string name;
	char* name;
	std::vector <Component *> overlapingComponents;
	
	//std::vector <Component *> startOverlapingComp;
	//std::vector <Component *> isOverlapingComp;
	//std::vector <Component *> endOverlapingComp;
	
	double localPositionX;
	double localPositionY;

	Transform wTransform;
public:
	Collision * collision;

	Component();
	//std::vector <Component *>& getStartOverlapingComp();
	//std::vector <Component *>& getIsOverlapingComp();
	//std::vector <Component *>& getEndOverlapingComp();
	
	void addOverlapComponent(Component*);
	Collision* getCollider();
	bool collides(Collision *otherCollider);

	virtual void setPosition(double, double) = 0;
	virtual void setLocalPosition(double, double);
	double getXWorldPosition();
	double getYWorldPosition();
	double getXWorldRotation() { return wTransform.rotationX; };
	void setLocalRotation(double x);
	virtual void render(sf::RenderWindow *) {};
	virtual void setRotation(double) {};
	virtual void setRotateToMovementDirection(bool a) {};
	virtual bool getRotateToMovementDirection() = 0;

	void setName(char* name);
	char* getName() const;
	//void overlapingEndMain();
	~Component();
};

#endif // !_Component_H_
