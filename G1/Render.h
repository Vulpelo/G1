#pragma once

#ifndef RENDER_H
#define RENDER_H

#include <SFML\Graphics.hpp>

#include "Properties.h"
#include "MapManager.h"
#include "GameMap.h"
#include "Map001.h"

class Render
{
	sf::RenderWindow * window;
public:
	Render();
	~Render();
	sf::RenderWindow*getWindow();
	void renderWindow();
};

#endif // !RENDER_H
