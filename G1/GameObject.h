#pragma once

#include "Object.h"
#include "PhysicsHandle.h"
#include "Mesh.h"
#include <iostream>

class GameObject : public Object
{
public:
	GameObject();
	GameObject(Transform nWTransform);
	~GameObject();
};

