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
	if (rate > 0 && this->velocity.y < this->maxWalkSpeedForwad)
	{
		this->velocity.y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate < 0 && this->velocity.y > -this->maxWalkSpeedForwad)
	{
		this->velocity.y += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingY = false;
	}
	else if (rate == 0)
		this->notMovingY = true;
}

void Player::movementRight(float rate)
{
	if (notMovingY == false) rate /= 2.0;
	if (rate > 0 && this->velocity.x < this->maxWalkSpeedRight)
	{
		this->velocity.x += rate * this->movementAcceleration * deltaTime.asSeconds();
		this->notMovingX = false;
	}
	else if (rate < 0 && this->velocity.x > -this->maxWalkSpeedRight)
	{
		this->velocity.x += rate * this->movementAcceleration * deltaTime.asSeconds();
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
		if (this->velocity.y < 0)
		{
			this->velocity.y += abs(cos(angle)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->velocity.y > 0)
			this->velocity.y -= abs(cos(angle)) * this->movementDecrementation * deltaTime.asSeconds();

		if (this->velocity.x < 0)
		{
			this->velocity.x += abs(sin(angle)) * this->movementDecrementation * deltaTime.asSeconds();
		}
		else if (this->velocity.x > 0)
			this->velocity.x -= abs(sin(angle)) * this->movementDecrementation * deltaTime.asSeconds();

	}
	else
	{
		if (notMovingY == true)
		{
			if (this->velocity.y < 0)
			{
				this->velocity.y += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->velocity.y > 0)
				this->velocity.y -= this->movementDecrementation * deltaTime.asSeconds();
		}
		if (notMovingX == true)
		{
			if (this->velocity.x < 0)
			{
				this->velocity.x += this->movementDecrementation * deltaTime.asSeconds();
			}
			else if (this->velocity.x > 0)
				this->velocity.x -= this->movementDecrementation * deltaTime.asSeconds();
		}
	}
}