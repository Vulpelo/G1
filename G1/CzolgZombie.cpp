#include "CzolgZombie.h"


CzolgZombie::CzolgZombie()
	:Actor()
{
	beginPlay();
}

CzolgZombie::CzolgZombie(Transform nWTransform)
	: Actor(nWTransform)
{
	beginPlay();
}

void CzolgZombie::beginPlay()
{
	//this->maxWalkSpeedForwad = 50.f;

	//int nrOfShapes = 2;
	//SimpleShape **sS = new SimpleShape*[nrOfShapes];
	//sS[0] = new Rectangle(54, 75, sf::Color(122, 255, 122, 255));
	//sS[1] = new Rectangle(40, 75, sf::Color(12, 255, 12, 255));
	//Mesh * m = new Mesh(sS, nrOfShapes);
	//m->setName("Body");
	//Collision *c = new CollisionRectangle(54, 54, 0, 0);
	//m->setCollider(c);
	//m->setRotateToMovementDirection(true);
	//this->components.push_back(m);

	//nrOfShapes = 2;
	//sS = new SimpleShape*[nrOfShapes];
	//sS[0] = new Rectangle(30, 40, sf::Color(255, 0, 0, 255));
	//sS[1] = new Rectangle(10, 40, sf::Color(255, 0, 0, 255));
	//sS[1]->setLocalCoordinate(0, 20);
	//m = new Mesh(sS, nrOfShapes);
	//m->setLocalPosition(0, 0);
	//m->setName("Gun");
	//m->setRotateToMovementDirection(true);
	//this->components.push_back(m);

	updateMesh();
}

void CzolgZombie::eventTick()
{
	simpleMoveTo(target->getWorldPosition().position, 10);
}


CzolgZombie::~CzolgZombie()
{
}

void CzolgZombie::startOverlaping(GameObject * obj)
{
	if (dynamic_cast<Bullet*>(obj)) {
		this->DestroyObject();
		obj->DestroyObject();
	}
}
