#include "Mesh_MojaPostac.h"



Mesh_MojaPostac::Mesh_MojaPostac()
{
	int nrOfShapes = 1;
	SimpleShape **sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(50, 50, sf::Color(0, 0, 255, 255));
	Mesh * m = new Mesh(sS, nrOfShapes);
	Collision *c = new CollisionRectangle(50, 50, 0, 0);
	m->setCollider(c);
	m->setRotateToMovementDirection(true);
	this->meshes.push_back(m);

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
	this->meshes.push_back(m);
}


Mesh_MojaPostac::~Mesh_MojaPostac()
{
}
