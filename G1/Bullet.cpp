#include "Bullet.h"

Bullet::Bullet()
	:Actor::Actor()
{
	beginPlay();
}

Bullet::Bullet(double x, double y, double rotate)
	:Actor(x,y, rotate)
{
	beginPlay();
}

void Bullet::beginPlay()
{
	this->actualMovement.y = 500;
	this->actualMovement.x = 0;
	this->lifeTime = 5;
	this->movementToRotationDirection = true;

	int nrOfShapes = 1;
	SimpleShape **sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(5, 15, sf::Color(255, 255, 0, 255));
	Mesh *m = new Mesh(sS, nrOfShapes);
	Collision *c = new CollisionCircle(8, 0, 0);
	m->setCollider(c);
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	updateMesh();
}

void Bullet::EventTick()
{

}

void Bullet::startOverlaping(Object *overlaped)
{
	if (dynamic_cast<Wall *>(overlaped) || dynamic_cast<Przeciwnik1 *>(overlaped))
	{
		DestroyObject();
	}
}

void Bullet::endOverlaping(Object *overlaped) 
{

}
