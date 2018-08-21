#pragma once

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Actor.h"
//#include "Object.h"
#include <vector>
//#include "PhysicsHandle.h"

class GameMap
{
protected:
	std::vector <Object *> objects;
	sf::Time deltaTime;
public:
	GameMap();
	/// <summary> Return's a colection of Objects that where
	/// created in this GameMap </summary>
	std::vector <Object*> getAllObjects();
	void mainEventTick(sf::Time deltaTime);
	virtual void EventTick() = 0; //rdzen ustalany od postaci
	virtual void render(sf::RenderWindow * w);
	void setInput(ControlInput * input);

	friend class PhysicsHandle;
};

#endif // !GAMEMAP_H
