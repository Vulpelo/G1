#pragma once

#include "Object.h"
#include "PhysicsHandle.h"
#include "Mesh.h"
#include <iostream>

class GameObject : public Object
{
	virtual void mainBeginPlay();
protected:
	virtual void mainEventTick(sf::Time deltaTime);

public:
	GameObject();
	GameObject(Transform nWTransform);
	~GameObject();
};

