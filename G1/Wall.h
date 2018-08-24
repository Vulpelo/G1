#pragma once
#include "Object.h"
#include "SimpleShape.h"
#include "Bullet.h"
#include "Mesh.h"

class Wall : public Object
{

public:
	Wall(Transform nWTransform);
	void beginPlay();
	void EventTick();

	void startOverlaping(Object *overlaped);
	//void destroyObject();

};