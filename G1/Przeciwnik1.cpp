#include "Przeciwnik1.h"


Przeciwnik1::Przeciwnik1()
	: Actor()
{
	beginPlay();
}

Przeciwnik1::Przeciwnik1(Transform nWTransform)
	:Actor(nWTransform)
{
	beginPlay();
}

Przeciwnik1::~Przeciwnik1()
{
}

void Przeciwnik1::beginPlay()
{
	this->maxWalkSpeedForwad = 100;
	this->maxWalkSpeedRight = 100;
	this->rotationSpeed = 500;
	this->havePlayerInput = true;
	this->movementToRotationDirection = false;
	this->movementAcceleration = 100;
	this->movementDecrementation = 150;
	//this->shootRate = 0.2;
	patrolPoints.push_back(Position(10, -10));
	patrolPoints.push_back(Position(10, -500));
	patrolPoints.push_back(Position(500, -500));
	patrolPoints.push_back(Position(500, -10));
	patrolNr = 0;

	int nrOfShapes = 1;
	SimpleShape **sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(50, 50, sf::Color(0, 0, 255, 255));
	Mesh * m = new Mesh(sS, nrOfShapes);
	Collision *c = new CollisionRectangle(50, 50, 0, 0);
	m->setCollider(c);
	m->setRotateToMovementDirection(true);
	this->components.push_back(m);

	nrOfShapes = 3;
	sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(75, 5, sf::Color(0, 255, 0, 255));
	//sS[0]->rotationByOwnOrigin(true);
	sS[0]->setLocalCoordinate(0, -30);
	sS[1] = new Circle(25, sf::Color(255, 0, 0, 255));
	sS[1]->rotationByOwnOrigin(true);
	sS[1]->setLocalCoordinate(0, 0);
	sS[2] = new Rectangle(8, 15, sf::Color(0, 255, 0, 255));
	sS[2]->rotationByOwnOrigin(true);
	sS[2]->setLocalCoordinate(10, 15);
	//sS[2] = new Triangle(12, 5);
	m = new Mesh(sS, nrOfShapes);
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	updateMesh();
}

void Przeciwnik1::EventTick()
{
	//if (simpleMoveTo(patrolPoints.at(patrolNr), 10))
	//{
	//	patrolNr++;
	//	if (patrolNr >= patrolPoints.size())
	//		patrolNr = 0;
	//}
}
void Przeciwnik1::startOverlaping(Object *overlaped)
{
	if (dynamic_cast<Bullet *>(overlaped))
	{
		DestroyObject();
	}
}

void Przeciwnik1::isOverlaping(Object *overlaped)
{
	//if (dynamic_cast<Bullet *>(overlaped))
	//{
	//	std::cout << "Przeciwnik1:isOverlaping:Bullet\n";
	//	//DestroyObject();
	//}
}

void Przeciwnik1::endOverlaping(Object *overlaped)
{
	//if (dynamic_cast<Bullet *>(overlaped))
	//{
	//	std::cout << "Przeciwnik1:endOverlaping:Bullet\n";
	//	//DestroyObject();
	//}
}
