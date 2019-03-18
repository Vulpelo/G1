#include "RenderManager.h"

namespace G1 {

	RenderManager::RenderManager()
	{
		window = new sf::RenderWindow(sf::VideoMode(Properties::width, Properties::height, Properties::bitPerPixel), "G1");
	}

	RenderManager::~RenderManager()
	{
		if (window)
			delete window;
	}

	sf::RenderWindow * RenderManager::getWindow()
	{
		return window;
	}

	void RenderManager::renderGameObjects(std::vector<GameObject*> gameObjects) {
		for (unsigned int i = 0; i < gameObjects.size(); i++)
			gameObjects.at(i)->render(window);
	}

	void RenderManager::renderWindow()
	{
		window->clear();

		auto gameObjects = MapManager::get_aMap()->getAllObjects();

		renderGameObjects(gameObjects);
		//MapManager::get_aMap()->render(window);

		window->display();
	}

}
