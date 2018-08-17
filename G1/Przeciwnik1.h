#pragma once
#include "Actor.h"
#include <vector>
#include "Bullet.h"
#include "Mesh.h"

class Przeciwnik1 : public Actor
{
private:
	std::vector<Position> patrolPoints;
	int patrolNr;

public:
	Przeciwnik1();
	Przeciwnik1(double x, double y, double rotate);
	~Przeciwnik1();

	void EventTick();
	void beginPlay();
	void startOverlaping(Object *overlaped);
	void isOverlaping(Object *overlaped);
	void endOverlaping(Object *overlaped);


};

