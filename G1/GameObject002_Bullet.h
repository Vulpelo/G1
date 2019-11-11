#pragma once
#include "GameObject.h"

#include "CircleRenderer.h"
#include "Rigidbody.h"
#include "CircleCollider.h"
#include <iostream>

using namespace G1;

class GameObject002_Bullet :
	public GameObject
{
public:
	GameObject002_Bullet();
	void beginPlay();
	void isColliding(GameObject*);
};

