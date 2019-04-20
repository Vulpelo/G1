#pragma once
// G1
#include "GameObject.h"
#include "CircleRenderer.h"

// Game
#include "GameObject002_Bullet.h"

using namespace G1;

class GameObject001 :
	public GameObject
{
	float speed;
	float shootingSpeed;
	float a_shootingSpeed;

	ControlInput c;
public:
	void beginPlay();
	void eventTick();

private:
	void movement();
	void shooting();
};
