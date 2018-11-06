#include "Engine.h"


Engine::Engine()
{
	controlInput = new ControlInput(render.getWindow());

	//DO GRY
	GameMap *map = new Map001;
	map->setInput(controlInput);
	MapManager::loadMap(map);
}

Engine::~Engine()
{
	if(controlInput) 
		delete controlInput;
}

void Engine::mainLoop()
{
	while (render.getWindow()->isOpen())
	{
		clock_t b1, e1, e, b = clock();
	
		mainEventTick();

		render.renderWindow();

		e = clock();
		Debug::addText(" overallTime:", e-b);
		Debug::addText(" FPS:", 1000./ (e - b));
		Debug::update();
		deltaTime = deltaClock.restart();
	}
}

void Engine::mainEventTick()
{
	MapManager::get_aMap()->mainEventTick(deltaTime);
	controlInput->mainEventTick();
}
