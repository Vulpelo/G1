#include "Engine.h"

namespace G1 {

	Engine::Engine()
	{
		controlInput = ControlInput::getInstantiate();
		controlInput->setRenderWindow(render.getWindow());

		//DO GRY
		//GameMap *map = new Map001();
		GameMap *map = new MapPlatformer01();
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
			mainEventTick();

			physics.handle();
			render.renderWindow();

			time.restart();
		}
	}

	void Engine::mainEventTick()
	{
		MapManager::get_aMap()->mainEventTick();

		controlInput->mainEventTick();
	}

}
