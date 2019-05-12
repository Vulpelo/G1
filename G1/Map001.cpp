#include "Map001.h"

Map001::Map001()
{
	{
		GameObject001* o = new GameObject001();
		o->setTransform(Transform(500, 300, 0));

		objects.push_back(o);
	}

	{
		GameObject003_wall* w = new GameObject003_wall();
		w->setTransform(Transform(700, 500, 45));

		objects.push_back(w);
	}

	{
		GameObject003_wall* w = new GameObject003_wall();
		w->setTransform(Transform(700, 300, 0));

		objects.push_back(w);
	}

	{
		GameObject004_CircleWall* w = new GameObject004_CircleWall();
		w->setTransform(Transform(700, 100, 0));

		objects.push_back(w);
	}

}

void Map001::EventTick()
{
}