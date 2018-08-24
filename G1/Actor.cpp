#include "Actor.h"
#include <iostream>

Actor::Actor() 
	: GameObject()
{
	mainBeginPlay();
}

Actor::Actor(double x, double y, double rotate)
	: GameObject(x, y, rotate)
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
}

void Actor::mainEventTick(sf::Time deltaTime)
{
	Object::mainEventTick(deltaTime);

	this->deltaTime = deltaTime;

	if (lifeTime > 0 && currentLifeTime <= lifeTime)
		currentLifeTime += deltaTime.asSeconds();
	
	movementAngle();
	updateMesh();
	worldCoordinateMovement();

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
			components.at(i)->setRotation(wTransform.rotationX);
	}

	/*---Mesh position---*/
	for (int i = 0; i<components.size(); i++)
		components.at(i)->setPosition(wTransform.position.X, wTransform.position.Y);
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
		this->wTransform.position.X += (actualMovement.y * sin((wTransform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->wTransform.position.Y += (actualMovement.y * cos((wTransform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();

		this->wTransform.position.X += (actualMovement.x * sin(((wTransform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->wTransform.position.Y += (actualMovement.x * cos(((wTransform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
	}
	else
	{
		this->wTransform.position.X += deltaTime.asSeconds() * actualMovement.x;
		this->wTransform.position.Y += deltaTime.asSeconds() * actualMovement.y;
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

//void Actor::movementForward(float rate)
//{
//	if (rate > 0 && this->actualMovement.y < this->maxWalkSpeedForwad)
//	{
//		this->actualMovement.y += rate * this->movementAcceleration * deltaTime.asSeconds();
//		this->notMovingY = false;
//	}
//	else if (rate < 0 && this->actualMovement.y > -this->maxWalkSpeedForwad)
//	{
//		this->actualMovement.y += rate * this->movementAcceleration * deltaTime.asSeconds();
//		this->notMovingY = false;
//	}
//	else if (rate == 0)
//		this->notMovingY = true;
//}
//
//void Actor::movementRight(float rate)
//{
//	if (notMovingY == false) rate /= 2.0;
//	if (rate > 0 && this->actualMovement.x < this->maxWalkSpeedRight)
//	{
//		this->actualMovement.x += rate * this->movementAcceleration * deltaTime.asSeconds();
//		this->notMovingX = false;
//	}
//	else if (rate < 0 && this->actualMovement.x > -this->maxWalkSpeedRight)
//	{
//		this->actualMovement.x += rate * this->movementAcceleration * deltaTime.asSeconds();
//		this->notMovingX = false;
//	}
//	else if (rate == 0)
//		this->notMovingX = true;
//}


//void Actor::movementDecrementacionF()
//{
//	if (notMovingX && notMovingY)
//	{
//		if (this->actualMovement.y < 0)
//		{
//			this->actualMovement.y += abs(cos(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
//		}
//		else if (this->actualMovement.y > 0)
//			this->actualMovement.y -= abs(cos(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
//
//		if (this->actualMovement.x < 0)
//		{
//			this->actualMovement.x += abs(sin(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
//		}
//		else if (this->actualMovement.x > 0)
//			this->actualMovement.x -= abs(sin(this->actualMovementAngleX)) * this->movementDecrementation * deltaTime.asSeconds();
//	
//	}
//	else
//	{
//		if (notMovingY == true)
//		{
//			if (this->actualMovement.y < 0)
//			{
//				this->actualMovement.y += this->movementDecrementation * deltaTime.asSeconds();
//			}
//			else if (this->actualMovement.y > 0)
//				this->actualMovement.y -= this->movementDecrementation * deltaTime.asSeconds();
//		}
//		if (notMovingX == true)
//		{
//			if (this->actualMovement.x < 0)
//			{
//				this->actualMovement.x += this->movementDecrementation * deltaTime.asSeconds();
//			}
//			else if (this->actualMovement.x > 0)
//				this->actualMovement.x -= this->movementDecrementation * deltaTime.asSeconds();
//		}
//	}
//}

bool Actor::simpleMoveTo(Position cor, double distancePrecision)
{
	double angle;
	if ( GMath::twoPointsDistance(this->wTransform.position.X, this->wTransform.position.Y, cor.X, cor.Y) > distancePrecision)
	{
		double angle = GMath::twoPointsAngle(this->wTransform.position.X, this->wTransform.position.Y, cor.X, cor.Y);
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
	if ((rot = GMath::twoPointsAngle(xCor, -yCor, point.X, -point.Y)) > anglePrecision)
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
	double rot = GMath::twoPointsAngle(xCor, -yCor, point.X, -point.Y);

	if (rot > anglePrecision) 
	{
		s->setLocalRotation(rot - s->getXWorldRotation());
		return false;
	}
	return true;
}

bool Actor::lookAt(Position point, double anglePrecision)
{
	this->wTransform.rotationX = GMath::twoPointsAngle
	(this->wTransform.position.X, this->wTransform.position.Y,
		point.X, -point.Y);

	//!!!!????!?!??!
	return false;
}
