#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01()
{
	{
		PlatformerPlayer* o = new PlatformerPlayer();
		o->setTransform(Transform(200, 400, 0));

		objects.push_back(o);
	}
	{
		Ground01* o = new Ground01(1000, 50);
		o->setTransform(Transform(500, 800, 0));

		objects.push_back(o);
	}
	{
		Ground01* o = new Ground01(50, 50);
		o->setTransform(Transform(700, 750, 0));

		objects.push_back(o);
	}

	{
		Ground01* o = new Ground01(50, 600);
		o->setTransform(Transform(900, 300, 0));

		objects.push_back(o);
	}
}
