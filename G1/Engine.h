#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Properties.h"

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "ControlInput.h"
#include "Time.h"
#include "EventHandler.h"

namespace G1 {

	class Engine
	{
		Time time;

		RenderManager& render = RenderManager::getInstance();
		PhysicsManager physics;

		ControlInput& controlInput = ControlInput::getInstantiate();

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
