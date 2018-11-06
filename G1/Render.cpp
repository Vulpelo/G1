#include "Render.h"

Render::Render()
{
	window = new sf::RenderWindow(sf::VideoMode(Properties::width, Properties::height, Properties::bitPerPixel), "G1");
}

Render::~Render()
{
	if (window)
		delete window;
}

sf::RenderWindow * Render::getWindow()
{
	return window;
}

void Render::renderWindow()
{
	window->clear();

	MapManager::get_aMap()->render(window);
	
	window->display();
}
