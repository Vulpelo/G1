#include "Map001.h"

Map001::Map001()
{
	GameObject001* o = new GameObject001();
	o->setTransform(Transform(100, 100, 0));

	objects.push_back(o);
}

void Map001::EventTick()
{
}