#pragma once

#ifndef _Component_H_
#define _Component_H_

//#include "SimpleShape.h"
#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
//#include "Collision.h"
#include "Transform.h"

class Component
{
	friend class PhysicsHandle;

	std::vector <Component *> newOverlapingComponents;

protected:
	//overlaping
	char* name;
	std::vector <Component *> overlapingComponents;
	
	Transform transform;

public:
	//Collision * collision;

	Component();
	
	void setName(char* name);
	char* getName() const;


	void addOverlapComponent(Component*);
	//Collision* getCollider();
	//bool collides(Collision *otherCollider);

	void setPosition(double, double);
	Vector2 getWorldPosition();
	
	void setTransform(Transform transform);
	Transform getTransform();

	double getWorldRotation() { return transform.rotationX; };
	void setRotation(double x);
	
	virtual void setRotateToMovementDirection(bool a) {};
	// virtual bool getRotateToMovementDirection() = 0;
	
	virtual void render(sf::RenderWindow *) {};
	
	//void overlapingEndMain();
	~Component();
};

#endif // !_Component_H_
