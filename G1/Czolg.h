#pragma once
#include "Player.h"
#include "Bullet.h"

class Czolg : public Player
{
private:
	float shootRate;
	float aShootRate;
public:
	Czolg();
	Czolg(Transform nWTransform);

	void beginPlay();
	void eventTick();
	void startOverlaping(GameObject *overlaped);
	void endOverlaping(GameObject *overlaped);
	void movement();//!-przeniesc do klasy wy¿ej_?
};

