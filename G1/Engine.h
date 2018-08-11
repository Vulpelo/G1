#pragma once
#include <SFML\Graphics.hpp>

#include "ControlInput.h"
#include "GameMap.h"

class Engine
{
private:
	sf::RenderWindow * window;
	sf::Event inputEvent;
	sf::Clock deltaClock;
	sf::Time deltaTime;
	
	ControlInput * controlInput;
	std::vector <GameMap *> map;
	GameMap *actualMap;

public:
	Engine();
	~Engine();
	void windowRender();
	void mainEventTick();
	void mainLoop();
	void loadMap(int);
};