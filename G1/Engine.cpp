#include "Engine.h"

namespace G1 {

	Engine::Engine()
	{
		controlInput.setRenderWindow(render.getWindow());
	}

	Engine::~Engine()
	{
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
		render.catchEvents();

		controlInput.mainEventTick();
		MapManager::getInstance().get_aMap().mainEventTick();
	}

}
