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
	void EventTick();

	void startOverlaping(Object *overlaped);
	void endOverlaping(Object *overlaped);
	//void isOverlaping(Object *overlaped);
};