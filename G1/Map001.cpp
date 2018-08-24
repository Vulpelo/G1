#include "Map001.h"
#include "MojaPostac.h"
#include "Czolg.h"
#include "Wall.h"
#include "CzolgZombie.h"
#include "Przeciwnik1.h"
#include <iostream>

Map001::Map001()
{
	objects.push_back(new Wall(Transform(Position(250, -100))));
	objects.push_back(new Wall(Transform(Position(350, -400))));
	objects.push_back(new Wall(Transform(Position(650, -300))));
	auto* player = new Czolg(Transform(Position(800, -400)));
	objects.push_back(player);
	
	auto* enemy = new CzolgZombie(Transform(Position(10, -10)));
	enemy->target = player;
	objects.push_back(enemy);

	objects.push_back(new Przeciwnik1(Transform(Position(100, -10))));
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