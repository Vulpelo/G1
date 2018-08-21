#pragma once

#include "Object.h"
#include "PhysicsHandle.h"
#include <iostream>

class GameObject : public Object
{
public:
	GameObject();
	GameObject(double, double, double);
	~GameObject();
};

