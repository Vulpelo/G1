#pragma once
#include "Player.h"
#include "Mesh.h"
#include "Bullet.h"

class Czolg : public Player
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

