#include "Player.h"



Player::Player()
	:Actor()
{
	mainBeginPlay();
}

Player::Player(Transform nWTransform)
	:Actor(nWTransform)
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
	if (rate > 0 && this->velocity.Y < this->maxWalkSpeedForwad)
	{
		this->velocity.Y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate < 0 && this->velocity.Y > -this->maxWalkSpeedForwad)
	{
		this->velocity.Y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate == 0)
		this->notMovingY = true;
}

void Player::movementRight(float rate)
{
	if (notMovingY == false) rate /= 2.0;
	if (rate > 0 && this->velocity.X < this->maxWalkSpeedRight)
	{
		this->velocity.X += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingX = false;
	}
	else if (rate < 0 && this->velocity.X > -this->maxWalkSpeedRight)
	{
		this->velocity.X += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingX = false;
	}
	else if (rate == 0)
		this->notMovingX = true;
}

void Player::movementDecrementacionF()
{
	float angle = this->velocity.angle();
	if (notMovingX && notMovingY)
	{
		if (this->velocity.Y < 0)
		{
			this->velocity.Y += abs(cos(angle)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->velocity.Y > 0)
			this->velocity.Y -= abs(cos(angle)) * this->movementDecrementation * deltaTime.asSeconds();

		if (this->velocity.X < 0)
		{
			this->velocity.X += abs(sin(angle)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->velocity.X > 0)
			this->velocity.X -= abs(sin(angle)) * this->movementDecrementation * deltaTime.asSeconds();

	}
	else
	{
		if (notMovingY == true)
		{
			if (this->velocity.Y < 0)
			{
				this->velocity.Y += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->velocity.Y > 0)
				this->velocity.Y -= this->movementDecrementation * deltaTime.asSeconds();
		}
		if (notMovingX == true)
		{
			if (this->velocity.X < 0)
			{
				this->velocity.X += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->velocity.X > 0)
				this->velocity.X -= this->movementDecrementation * deltaTime.asSeconds();
		}
	}
}