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
	Przeciwnik1(Transform nWTransform);
	~Przeciwnik1();

	void eventTick();
	void beginPlay();
	void startOverlaping(GameObject *overlaped);
	void isOverlaping(GameObject *overlaped);
	void endOverlaping(GameObject *overlaped);


};

