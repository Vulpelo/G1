#include "Map001.h"

Map001::Map001()
{

	//{
	//	GameObject003_wall* w = new GameObject003_wall();
	//	w->setTransform(Transform(700, 500, 45));

	//	objects.push_back(w);
	//}

	//{
	//	GameObject003_wall* w = new GameObject003_wall(60, 100);
	//	w->setTransform(Transform(400, 500, 45));

	//	objects.push_back(w);
	//}

	//{
	//	GameObject003_wall* w = new GameObject003_wall(60, 60);
	//	w->setTransform(Transform(700, 300, 0));

	//	objects.push_back(w);
	//}


	{
		GameObject003_wall* w = new GameObject003_wall(50, 50, true);
		w->setTransform(Transform(600, 100, 0));

		objects.push_back(w);
	}
	{
		GameObject003_wall* w = new GameObject003_wall(50, 50, true);
		w->setTransform(Transform(670, 100, 0));

		objects.push_back(w);
	}
	{
		GameObject003_wall* w = new GameObject003_wall(50, 50, true);
		w->setTransform(Transform(670, 170, 0));

		objects.push_back(w);
	}
	{
		GameObject003_wall* w = new GameObject003_wall(50, 50, true);
		w->setTransform(Transform(600, 170, 0));

		objects.push_back(w);
	}


	{
		GameObject003_wall* w = new GameObject003_wall(1000, 50, false);
		w->setTransform(Transform(500, 800, 0));

		objects.push_back(w);
	}

	{
		GameObject004_CircleWall* w = new GameObject004_CircleWall();
		w->setTransform(Transform(100, 300, 0));

		objects.push_back(w);
	}
	{
		GameObject004_CircleWall* w = new GameObject004_CircleWall();
		w->setTransform(Transform(240, 320, 0));

		objects.push_back(w);
	}

	{
		GameObject002_Bullet* b = new GameObject002_Bullet(0);
		b->setTransform(Transform(100, 600, 0));

		objects.push_back(b);
	}
	{
		GameObject002_Bullet* b = new GameObject002_Bullet(0.5);
		b->setTransform(Transform(150, 600, 0));

		objects.push_back(b);
	}
	{
		GameObject002_Bullet* b = new GameObject002_Bullet(1);
		b->setTransform(Transform(200, 600, 0));

		objects.push_back(b);
	}
	{
		GameObject002_Bullet* b = new GameObject002_Bullet(2);
		b->setTransform(Transform(250, 600, 0));

		objects.push_back(b);
	}


	{
		GameObject001* o = new GameObject001();
		o->setTransform(Transform(489, 222.051f, 0));

		objects.push_back(o);
	}
}

void Map001::EventTick()
{
}