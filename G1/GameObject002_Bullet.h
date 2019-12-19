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
	Rigidbody* rb = NULL;

public:
	GameObject002_Bullet() {};
	GameObject002_Bullet(float bounciness);
	void beginPlay();
	void eventTick();
	void isColliding(GameObject*);
};

