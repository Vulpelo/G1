#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Properties.h"

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "ControlInput.h"
#include "Time.h"


// for game
#include "MapPlatformer01.h"
#include "Map001.h"
//

namespace G1 {

	class Engine
	{
	private:
		Time time;

		sf::Event inputEvent;

		RenderManager& render = RenderManager::getInstance();
		PhysicsManager physics;

		ControlInput * controlInput;

		void mainEventTick();
		void mainLoop();

	protected:
		virtual void beginPlay() = 0;

	public:
		Engine();
		~Engine();
		void start();
	};

}

#endif // !_ENGINE_H_
