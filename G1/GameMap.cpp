#include "GameMap.h"
#include <iostream>

GameMap::GameMap() {}

std::vector<Object*> GameMap::getAllObjects()
{
	return objects;
}

void GameMap::mainEventTick(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;

	/*---Destroing objects or do mainEventTick---*/
	for (unsigned int i = objects.size(); i > 0; i--)
	{
		if (objects.at(i-1)->shouldBeDestroyed())
			objects.erase(objects.begin() + (i-1));
		else
			objects.at(i-1)->mainEventTick(deltaTime);
	}

	/*---Checking collisions---*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < objects.size(); j++)
			if (objects.at(i)->isCollidingObjectM(objects.at(j)))
			{
				objects.at(i)->overlapingMain(objects.at(j));
				objects.at(j)->overlapingMain(objects.at(i));
			}
	}

	/*---Update data about overlaping objects---*/
	for (unsigned int i = 0; i < objects.size(); i++)
		objects.at(i)->overlapingEndMain();


	/*--Spawning new actors--*/
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (Actor* act = dynamic_cast <Actor*>(objects.at(i)))
		{
			std::vector <Object*> ac = act->toSpawn();
			while (!ac.empty())
			{
				this->objects.push_back(ac.back());
				ac.pop_back();
			}
		}
	}
	this->EventTick();
}

void GameMap::render(sf::RenderWindow * w)
{
	for (unsigned int i = 0; i < objects.size(); i++)
		objects.at(i)->render(w);
}

void GameMap::setInput(ControlInput * input)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (Actor *ac = dynamic_cast <Actor*>(objects.at(i)))
		{
			if (ac->hasPlayerInput())
				ac->setPlayerInput(input);
		}
	}
}