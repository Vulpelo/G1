#include "Engine.h"

namespace G1 {

	Engine::Engine()
	{
		controlInput = ControlInput::getInstantiate();
		controlInput->setRenderWindow(render.getWindow());
	}

	Engine::~Engine()
	{
		if(controlInput) 
			delete controlInput;
	}

	void Engine::start() {
		beginPlay();
		mainLoop();
	}

	void Engine::mainLoop()
	{
		while (render.getWindow().isOpen())
		{
			mainEventTick();

			physics.handle();
			render.renderWindow();

			time.restart();
		}
	}

	void Engine::mainEventTick()
	{
		MapManager::getInstance().get_aMap().mainEventTick();

		controlInput->mainEventTick();
	}

}
