#include "Player.h"



Player::Player()
	:Actor()
{
	mainBeginPlay();
}

Player::Player(double x, double y, double rotate)
	:Actor(x, y, rotate)
{
	mainBeginPlay();
}

void Player::mainBeginPlay()
{
}

void Player::mainEventTick(sf::Time deltaTime) {
	Actor::mainEventTick(deltaTime);

	movementDecrementacionF();

}

Player::~Player()
{
}

void Player::movementForward(float rate)
{
	if (rate > 0 && this->actualMovement.y < this->maxWalkSpeedForwad)
	{
		this->actualMovement.y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate < 0 && this->actualMovement.y > -this->maxWalkSpeedForwad)
	{
		this->actualMovement.y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate == 0)
		this->notMovingY = true;
}

void Player::movementRight(float rate)
{
	if (notMovingY == false) rate /= 2.0;
	if (rate > 0 && this->actualMovement.x < this->maxWalkSpeedRight)
	{
		this->actualMovement.x += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingX = false;
	}
	else if (rate < 0 && this->actualMovement.x > -this->maxWalkSpeedRight)
	{
		this->actualMovement.x += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingX = false;
	}
	else if (rate == 0)
		this->notMovingX = true;
}

void Player::movementDecrementacionF()
{
	if (notMovingX && notMovingY)
	{
		if (this->actualMovement.y < 0)
		{
			this->actualMovement.y += abs(cos(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->actualMovement.y > 0)
			this->actualMovement.y -= abs(cos(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();

		if (this->actualMovement.x < 0)
		{
			this->actualMovement.x += abs(sin(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->actualMovement.x > 0)
			this->actualMovement.x -= abs(sin(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();

	}
	else
	{
		if (notMovingY == true)
		{
			if (this->actualMovement.y < 0)
			{
				this->actualMovement.y += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->actualMovement.y > 0)
				this->actualMovement.y -= this->movementDecrementation * deltaTime.asSeconds();
		}
		if (notMovingX == true)
		{
			if (this->actualMovement.x < 0)
			{
				this->actualMovement.x += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->actualMovement.x > 0)
				this->actualMovement.x -= this->movementDecrementation * deltaTime.asSeconds();
		}
	}
}