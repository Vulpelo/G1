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
			components.at(i)->setRotation(transform.rotationX);
	}

	/*---Mesh position---*/
	for (int i = 0; i<components.size(); i++)
		components.at(i)->setPosition(transform.position.X, transform.position.Y);
}


void Actor::worldCoordinateMovement()
{
	if (movementToRotationDirection)
	{
		this->transform.position.X += (velocity.Y * sin((transform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->transform.position.Y += (velocity.Y * cos((transform.rotationX * M_PI) / 180.0)) * deltaTime.asSeconds();

		this->transform.position.X += (velocity.X * sin(((transform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
		this->transform.position.Y += (velocity.X * cos(((transform.rotationX + 90) * M_PI) / 180.0)) * deltaTime.asSeconds();
	}
	else
	{
		this->transform.position.X += deltaTime.asSeconds() * velocity.X;
		this->transform.position.Y += deltaTime.asSeconds() * velocity.Y;
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
	if ( GMath::twoPointsDistance(this->transform.position.X, this->transform.position.Y, cor.X, cor.Y) > distancePrecision)
	{
		double angle = GMath::twoPointsAngle(this->transform.position.X, this->transform.position.Y, cor.X, cor.Y);
		velocity.setVectorByAngleAndLength(angle, maxWalkSpeedForwad);
		return false;
	}
	velocity.setVector(0,0);
	return true;
}

bool Actor::simpleMoveTo(Vector2D cor, double distancePrecision)
{
	double angle;
	if (GMath::twoPointsDistance(this->transform.position.X, this->transform.position.Y, cor.X, cor.Y) > distancePrecision)
	{
		double angle = GMath::twoPointsAngle(this->transform.position.X, this->transform.position.Y, cor.X, cor.Y);
		velocity.setVectorByAngleAndLength(angle, maxWalkSpeedForwad);
		return false;
	}
	velocity.setVector(0, 0);
	return true;
}

bool Actor::lookAt(Component *m, Position point, double anglePrecision)
{
	double xCor = m->getXWorldPosition();
	double yCor = m->getYWorldPosition();
	double rot;
	if ((rot = GMath::twoPointsAngle(xCor, -yCor, point.X, -point.Y)) > anglePrecision)
	{
		m->setRotation(rot - m->getWorldRotation());
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
		s->setRotation(rot - s->getXWorldRotation());
		return false;
	}
	return true;
}

bool Actor::lookAt(Position point, double anglePrecision)
{
	this->transform.rotationX = GMath::twoPointsAngle
	(this->transform.position.X, this->transform.position.Y,
		point.X, -point.Y);

	//!!!!????!?!??!
	return false;
}
