#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "Properties.h"

#include "Render.h"
#include "ControlInput.h"

class Engine
{
private:
	sf::Event inputEvent;
	sf::Clock deltaClock;
	sf::Time deltaTime;
	Render render;
	
	ControlInput * controlInput;

public:
	Engine();
	~Engine();
	void mainEventTick();
	void mainLoop();
};

#endif // !ENGINE_H
