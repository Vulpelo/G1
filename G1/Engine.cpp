#include "Engine.h"

#include "Properties.h"
#include "Map001.h"

#include <iostream>

Engine::Engine()
{
	window = new sf::RenderWindow(sf::VideoMode(Properties::width, Properties::height, Properties::bitPerPixel), "G1");
	controlInput = new ControlInput(window);

	//DO GRY
	GameMap *map = new Map001;
	map->setInput(controlInput);
	Properties::loadMap(map);
}

Engine::~Engine()
{
	if(controlInput) 
		delete controlInput;
	if(window)
		delete window;
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

void Engine::mainEventTick()
{
	Properties::get_aMap()->mainEventTick(deltaTime);
	controlInput->mainEventTick();
}

void Engine::windowRender()
{
	Properties::get_aMap()->render(window);
}

