#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"

class Player : public Actor
{
private:
	bool notMovingX;
	bool notMovingY;
	void mainBeginPlay();
	void mainEventTick(sf::Time deltaTime);
public:
	Player();
	Player(Transform nWTransform);
	
	~Player();

	//rate is from -1 to 1
	void movementForward(float rate);
	void movementRight(float rate);

	void movementDecrementacionF();
};

#endif // !PLAYER_H
