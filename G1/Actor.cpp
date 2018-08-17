#include "Actor.h"
#include <iostream>

Actor::Actor() 
	: Object()
{
	mainBeginPlay();
}

Actor::Actor(double x, double y, double rotate)
	: Object(x, y, rotate)
{
	mainBeginPlay();
}

void Actor::mainBeginPlay()
{
	this->havePlayerInput = false;

	this->maxWalkSpeedForwad = 100;
	this->maxWalkSpeedRight = 100;
	this->rotationSpeed = 200;
	this->havePlayerInput = true;
	this->movementToRotationDirection = false;
	this->movementAcceleration = 100;
	this->movementDecrementation = 100;
	this->lifeTime = 0;
	this->currentLifeTime = 0;

	this->gravity = 100.f;
}

void Actor::mainEventTick(sf::Time deltaTime)
{
	Object::mainEventTick(deltaTime);

	movementDecrementacionF();

	this->deltaTime = deltaTime;

	if (lifeTime > 0 && currentLifeTime <= lifeTime)
		currentLifeTime += deltaTime.asSeconds();
	
	movementAngle();
	updateMesh();
	worldCoordinateMovement();

	//actualMovement.y -= gravity * deltaTime.asSeconds();

	EventTick();
}

void Actor::updateMesh()
{
	/*---Mesh rotation---*/
	for (int i = 0; i < components.size(); i++)
	{
		if (components.at(i)->getRotateToMovementDirection())
			components.at(i)->setRotation(actualMovementAngleX);
		else
			components.at(i)->setRotation(worldRotationX);
	}

	/*---Mesh position---*/
	for (int i = 0; i<components.size(); i++)
		components.at(i)->setPosition(worldCoordinateX, worldCoordinateY);
}

void Actor::movementAngle()
{
	if (actualMovement.x > 10 || actualMovement.x < -10
		|| actualMovement.y > 10 || actualMovement.y < -10)
		actualMovementAngleX = (180 * atan(actualMovement.x / actualMovement.y)) / M_PI;
}



void Actor::worldCoordinateMovement()
{
	if (movementToRotationDirection)
	{
		this->worldCoordinateX += (actualMovement.y * sin((worldRotationX * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->worldCoordinateY += (actualMovement.y * cos((worldRotationX * M_PI) / 180.0)) * deltaTime.asSeconds();

		this->worldCoordinateX += (actualMovement.x * sin(((worldRotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->worldCoordinateY += (actualMovement.x * cos(((worldRotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
	}
	else
	{
		this->worldCoordinateX += deltaTime.asSeconds() * actualMovement.x;
		this->worldCoordinateY += deltaTime.asSeconds() * actualMovement.y;
	}
}

void Actor::setPlayerInput(ControlInput * input)
{
	playerInput = input;
}

bool Actor::hasPlayerInput()
{
	return havePlayerInput;
}

std::vector <Object*> Actor::toSpawn()
{
	std::vector <Object*> actorss;
	if (objectsToSpawn.size() > 0)
	{
		actorss = objectsToSpawn;
		objectsToSpawn.clear();
		return actorss;
	}
	return actorss;
}

void Actor::spawnObject(Object* a)
{
	objectsToSpawn.push_back(a);
}

void Actor::movementForward(float rate)
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

void Actor::movementRight(float rate)
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


void Actor::movementDecrementacionF()
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

bool Actor::simpleMoveTo(Position cor, double distancePrecision)
{
	double angle;
	if ( MathFunction::twoPointsDistance(this->worldCoordinateX, this->worldCoordinateY, cor.X, cor.Y) > distancePrecision)
	{
		double angle = MathFunction::twoPointsAngle(this->worldCoordinateX, this->worldCoordinateY, cor.X, cor.Y);
		actualMovement.setVectorByAngleAndLength(angle, maxWalkSpeedForwad);
		return false;
	}
	actualMovement.setVector(0,0);
	return true;
}

bool Actor::lookAt(Component *m, Position point, double anglePrecision)
{
	double xCor = m->getXWorldPosition();
	double yCor = m->getYWorldPosition();
	double rot;
	if ((rot = MathFunction::twoPointsAngle(xCor, -yCor, point.X, -point.Y)) > anglePrecision)
	{
		m->setLocalRotation(rot - m->getXWorldRotation());
		return false;
	}
	return true;
}

bool Actor::lookAt(SimpleShape *s, Position point, double anglePrecision)
{
	double xCor = s->getXWorldPosition();
	double yCor = s->getYWorldPosition();
	double rot = MathFunction::twoPointsAngle(xCor, -yCor, point.X, -point.Y);

	if (rot > anglePrecision) 
	{
		s->setLocalRotation(rot - s->getXWorldRotation());
		return false;
	}
	return true;
}

bool Actor::lookAt(Position point, double anglePrecision)
{
	this->worldRotationX = MathFunction::twoPointsAngle
	(this->worldCoordinateX, this->worldCoordinateY,
		point.X, -point.Y);

	//!!!!????!?!??!
	return false;
}
