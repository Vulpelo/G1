#pragma once
#include "Actor.h"
#include "Mesh.h"
#include "Bullet.h"

class Czolg : public Actor
{
private:
	float shootRate;
	float aShootRate;
public:
	Czolg();
	Czolg(double x, double y, double rotate);

	void beginPlay();
	void EventTick();

	void movement();//!-przeniesc do klasy wy¿ej_?
};

