#include "Actor.h"
#include <iostream>

Actor::Actor() 
	: GameObject()
{
	mainBeginPlay();
}

Actor::Actor(Transform nWTransform)
	: GameObject(nWTransform)
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
}

void Actor::mainEventTick(sf::Time deltaTime)
{
	GameObject::mainEventTick(deltaTime);

	this->deltaTime = deltaTime;

	//if (lifeTime > 0 && currentLifeTime <= lifeTime)
	//	currentLifeTime += deltaTime.asSeconds();
	
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
			components.at(i)->setRotation(velocity.angle());
		else
			components.at(i)->setRotation(wTransform.rotationX);
	}

	/*---Mesh position---*/
	for (int i = 0; i<components.size(); i++)
		components.at(i)->setPosition(wTransform.position.X, wTransform.position.Y);
}


void Actor::worldCoordinateMovement()
{
	if (movementToRotationDirection)
	{
		this->wTransform.position.X += (velocity.y * sin((wTransform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->wTransform.position.Y += (velocity.y * cos((wTransform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();

		this->wTransform.position.X += (velocity.x * sin(((wTransform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->wTransform.position.Y += (velocity.x * cos(((wTransform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
	}
	else
	{
		this->wTransform.position.X += deltaTime.asSeconds() * velocity.x;
		this->wTransform.position.Y += deltaTime.asSeconds() * velocity.y;
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

bool Actor::simpleMoveTo(Position cor, double distancePrecision)
{
	double angle;
	if ( GMath::twoPointsDistance(this->wTransform.position.X, this->wTransform.position.Y, cor.X, cor.Y) > distancePrecision)
	{
		double angle = GMath::twoPointsAngle(this->wTransform.position.X, this->wTransform.position.Y, cor.X, cor.Y);
		velocity.setVectorByAngleAndLength(angle, maxWalkSpeedForwad);
		return false;
	}
	velocity.setVector(0,0);
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
