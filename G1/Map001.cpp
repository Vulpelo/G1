#include "Map001.h"
#include "MojaPostac.h"
#include "Czolg.h"
#include "Wall.h"
#include "Przeciwnik1.h"
#include <iostream>

Map001::Map001()
{
	objects.push_back(new Wall(250, -100, 0));
	objects.push_back(new Wall(350, -400, 0));
	objects.push_back(new Wall(650, -300, 0));
	objects.push_back(new Czolg(800, -400, 0));

	//objects.push_back(new Przeciwnik1(400, -400, 0));
	spawnEnemyTime = 3;
	actualSpawnEnemyTime = 0;
}

void Map001::EventTick()
{
	//if (actualSpawnEnemyTime >= spawnEnemyTime)
	//{
	//	objects.push_back(new Przeciwnik1(400, -400, 0));
	//	actualSpawnEnemyTime = 0;
	//}
	//actualSpawnEnemyTime += deltaTime.asSeconds();
}