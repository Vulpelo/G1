#include "Wall.h"


Wall::Wall(Transform nWTransform)
	: Object(nWTransform)
{
	beginPlay();
}

void Wall::beginPlay()
{
	SimpleShape **sS = new SimpleShape*[1];
	sS[0] = new Rectangle(100, 150, sf::Color(125, 255, 125, 255));
	Mesh *m = new Mesh(sS, 1);
	Collision *c = new CollisionRectangle(100, 150, 0, 0);
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
