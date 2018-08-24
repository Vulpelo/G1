#pragma once

#include "Actor.h"
#include "Bullet.h"
#include "Mesh.h"

class MojaPostac : public Actor
{
private:
	//pressing forward moves actor to the direction depend of rotation 
	//!-przeniesc do klasy wy¿ej

	double shootRate;
	double spawnRate;

public:
	MojaPostac();
	MojaPostac(double x, double y, double rotate);
	void beginPlay();
	void EventTick();
	void movement();//!-przeniesc do klasy wy¿ej_?
	void worldCoordinateMovement();

};