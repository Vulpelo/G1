#include "Wall.h"


Wall::Wall(Transform nWTransform)
	: Object(nWTransform)
{
	beginPlay();
}

void Wall::beginPlay()
{
	SimpleShape **sS = new SimpleShape*[3];
	sS[0] = new Rectangle(100, 150, sf::Color(125, 255, 125, 255));
	sS[1] = new Rectangle(100, 150, sf::Color(125, 0, 125, 125));
	sS[1]->setLocalRotation(-45);
	sS[2] = new Rectangle(100, 150, sf::Color(125, 0, 0, 125));
	sS[2]->setLocalRotation(-90);
	Mesh *m = new Mesh(sS, 3);
	Collision *c = new CollisionRectangle(100, 150, 0, 0, 0);
	m->setCollider(c);
	components.push_back(m);

	updateMesh();
}

void Wall::EventTick()
{

}

void Wall::startOverlaping(Object *overlaped)
{
	if (dynamic_cast<Bullet *>(overlaped))
	{
		//DestroyObject();
	}
}
