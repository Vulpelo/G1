#pragma once
#include "Actor.h"
#include "Bullet.h"

class CzolgZombie : public Actor
{
public:
	Object* target;

	CzolgZombie();
	CzolgZombie(Transform nWTransform);
	void beginPlay();
	void EventTick();
	~CzolgZombie();

	void startOverlaping(Object* obj);
};

