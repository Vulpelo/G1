#include "MojaPostac.h"
#include <iostream>
#include "Mesh.h"
#include "Przeciwnik1.h"

MojaPostac::MojaPostac(double x, double y, double rotate)
	:Actor(x, y, rotate)
{
	beginPlay();
}
MojaPostac::MojaPostac()
	:Actor()
{
	beginPlay();
}

void MojaPostac::beginPlay()
{
	this->maxWalkSpeedForwad = 100;
	this->maxWalkSpeedRight = 100;
	this->rotationSpeed = 200;
	this->havePlayerInput = true;
	this->movementToRotationDirection = false;
	this->movementAcceleration = 100;
	this->movementDecrementation = 150;
	this->shootRate = 0.2;


	int nrOfShapes = 1;
	SimpleShape **sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(50, 50, sf::Color(0, 0, 255, 255));
	Mesh * m = new Mesh(sS, nrOfShapes);
	m->setName("Legs");
	Collision *c = new CollisionRectangle(50,50,0,0);
	m->setCollider(c);
	m->setRotateToMovementDirection(true);
	this->components.push_back(m);

	nrOfShapes = 4;
	sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(75, 5, sf::Color(220,255,0,255));
	sS[0]->rotationByOwnOrigin(true);
	sS[0]->setLocalCoordinate(0, 0);

	sS[1] = new Circle(25, sf::Color(255,0,0,255));
	sS[1]->rotationByOwnOrigin(true);
	sS[1]->setLocalCoordinate(0, 0);

	sS[2] = new Rectangle(75, 5, sf::Color(220, 255, 0, 255));
	sS[2]->rotationByOwnOrigin(true);
	sS[2]->setLocalCoordinate(0, -70);

	sS[3] = new Circle(25, sf::Color(255, 125, 0, 255));
	sS[3]->rotationByOwnOrigin(true);
	sS[3]->setLocalCoordinate(0, -70);

	//sS[2] = new Rectangle(8, 15, sf::Color(0, 255, 0, 255));
	//sS[2]->rotationByOwnOrigin(true);
	//sS[2]->setLocalCoordinate(10, 15);
	//sS[2] = new Triangle(12, 5);
	m = new Mesh(sS, nrOfShapes);
	m->setName("Body");
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	nrOfShapes = 1;
	sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(8, 15, sf::Color(0, 255, 0, 255));
	sS[0]->rotationByOwnOrigin(true);
	sS[0]->setLocalCoordinate(0, 0);
	m = new Mesh(sS, nrOfShapes);
	m->setLocalPosition(10, 10);
	m->setName("Gun");
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	updateMesh();
}

void MojaPostac::EventTick()
{
	movement();
	//rotation
	this->wTransform.rotationX = GMath::twoPointsAngle
		(this->wTransform.position.X, this->wTransform.position.Y,
			this->playerInput->mousePosition().x, -this->playerInput->mousePosition().y);

	double xCor = components.at(2)->getXWorldPosition();
	double yCor = components.at(2)->getYWorldPosition();
	double rot = GMath::twoPointsAngle
	(xCor, -yCor, this->playerInput->mousePosition().x, -this->playerInput->mousePosition().y);

	//components.at(2)->setLocalRotation(rot - components.at(2)->getXWorldRotation());

	//if (playerInput->left_KeyboardKeyPressed())
	//{
	//	this->wTransform.rotationX -= deltaTime.asSeconds() * rotationSpeed;
	//}
	//if (playerInput->right_KeyboardKeyPressed())
	//{
	//	this->wTransform.rotationX += deltaTime.asSeconds() * rotationSpeed;
	//}

	//shooting
	if (playerInput->down_KeyboardKeyPressed())
	{
		if (this->spawnRate <= 0)
		{
			spawnObject(new Przeciwnik1(400, -400, 0));
			this->spawnRate = 1;
		}
	}
	if (playerInput->up_KeyboardKeyPressed() )//|| playerInput->leftMouseButtonPressed())
	{
		if (this->shootRate <= 0)
		{
			this->shootRate = 0.15;
			spawnObject(new Bullet(components.at(2)->getXWorldPosition(), -components.at(2)->getYWorldPosition(), rot));
		}
	}
	shootRate -= deltaTime.asSeconds();
	spawnRate-= deltaTime.asSeconds();

}


void MojaPostac::movement()
{
	//movement
	if (playerInput->w_KeyboardKeyPressed() || playerInput->s_KeyboardKeyPressed())
	{
		if (playerInput->w_KeyboardKeyPressed())
			movementForward(1);
		else if (playerInput->s_KeyboardKeyPressed())
			movementForward(-1);
	}
	else
		movementForward(0);
	if(playerInput->d_KeyboardKeyPressed() || playerInput->a_KeyboardKeyPressed())
	{
		if (playerInput->d_KeyboardKeyPressed())
			movementRight(1);
		else if (playerInput->a_KeyboardKeyPressed())
			movementRight(-1);
	}
	else
		movementRight(0);
}
