#pragma once

#include "Actor.h"
#include "Wall.h"
#include "Przeciwnik1.h"
#include <iostream>
#include "Mesh.h"

class Bullet : public Actor
{
private:

public:
	Bullet();
	Bullet(Transform nWTransform);
	void beginPlay();
	void eventTick();

	void startOverlaping(GameObject *overlaped);
	void endOverlaping(GameObject *overlaped);
	//void isOverlaping(GameObject *overlaped);
};