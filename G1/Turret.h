#pragma once
#include "Actor.h"
#include <vector>
#include "Mesh.h"

class Turret : public Actor
{
public:
	Turret();
	~Turret();
	void EventTick();
	void beginPlay();
};

