#pragma once
#include "GameObject.h"
#include "SimpleShape.h"
#include "Bullet.h"
#include "Mesh.h"

class Wall : public GameObject
{

public:
	Wall(Transform nWTransform);
	void beginPlay();
	void eventTick();

	void startOverlaping(GameObject *overlaped);
	//void destroyObject();

};