#pragma once
#include "Object.h"
#include "SimpleShape.h"
#include "Bullet.h"
#include "Mesh.h"

class Wall : public Object
{

public:
	Wall(double x, double y, double rotate);
	void beginPlay();
	void EventTick();

	void startOverlaping(Object *overlaped);
	//void destroyObject();

};