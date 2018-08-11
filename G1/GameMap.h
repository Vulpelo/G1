#pragma once
#include "Actor.h"
#include "Object.h"
#include <vector>

class GameMap
{
protected:
	//Actor ** actors;
	//std::vector <Actor *> actors;
	std::vector <Object *> objects;
	sf::Time deltaTime;

public:
	GameMap();
	void mainEventTick(sf::Time deltaTime);
	virtual void EventTick() = 0; //rdzen ustalany od postaci
	virtual void render(sf::RenderWindow * w);
	void setInput(ControlInput * input);
};