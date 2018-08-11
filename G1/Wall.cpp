#include "Wall.h"


Wall::Wall(double x, double y, double rotate)
	: Object(x,y,rotate)
{
	SimpleShape **sS = new SimpleShape*[1];
	sS[0] = new Rectangle(100, 150, sf::Color(125, 255, 125, 255));
	Mesh *m = new Mesh(sS, 1);
	Collision *c = new CollisionRectangle(100, 150, 0, 0);
	m->setCollider(c);
	components.push_back(m);

	Object::beginPlay();
}

void Wall::beginPlay()
{

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
