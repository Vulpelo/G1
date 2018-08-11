#include "Engine.h"

#include "Map001.h"

#include <iostream>

Engine::Engine()
{
	window = new sf::RenderWindow(sf::VideoMode(1248, 900, 32), "G1");
	controlInput = new ControlInput(window);

	//DO GRY
	map.push_back(new Map001);
	map.at(0)->setInput(controlInput);
	actualMap = map.at(0);
	//
}

Engine::~Engine()
{
	for (GameMap* m : map)
		delete m;
	map.clear();
}

void Engine::mainLoop()
{
	while (window->isOpen())
	{
		mainEventTick();

		window->clear();
		windowRender();
		window->display();

		deltaTime = deltaClock.restart();
	}
}

void Engine::loadMap(int a)
{
	actualMap = map.at(a);
}

void Engine::mainEventTick()
{
	actualMap->mainEventTick(deltaTime);
	controlInput->mainEventTick();
}

void Engine::windowRender()
{
	actualMap->render(window);
}

