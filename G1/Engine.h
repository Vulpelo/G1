#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Properties.h"

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "ControlInput.h"
#include "Time.h"


// for game
#include "Map001.h"

namespace G1 {

	class Engine
	{
	private:
		Time time;

		sf::Event inputEvent;

		RenderManager render;
		PhysicsManager physics;

		ControlInput * controlInput;

	public:
		Engine();
		~Engine();
		void mainEventTick();
		void mainLoop();
	};

}

#endif // !_ENGINE_H_
