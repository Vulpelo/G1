#pragma once
#include "Actor.h"
#include "Bullet.h"

class CzolgZombie : public Actor
{
public:
	GameObject* target;

	CzolgZombie();
	CzolgZombie(Transform nWTransform);
	void beginPlay();
	void eventTick();
	~CzolgZombie();

	void startOverlaping(GameObject* obj);
};

