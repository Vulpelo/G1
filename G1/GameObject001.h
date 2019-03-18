#pragma once
#include "GameObject.h"

#include "CircleRenderer.h"

using namespace G1;

class GameObject001 :
	public GameObject
{
public:
	void beginPlay();
	void eventTick();
};

