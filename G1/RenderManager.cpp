#include "RenderManager.h"

namespace G1 {

	RenderManager::RenderManager()
	{
		window = new sf::RenderWindow(sf::VideoMode(Properties::width, Properties::height, Properties::bitPerPixel), 
			"G1",
			sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	}

	RenderManager::~RenderManager()
	{
		if (window)
			delete window;
	}

	sf::RenderWindow& RenderManager::getWindow()
	{
		sf::RenderWindow rw(sf::VideoMode);
		return *window;
	}

	void RenderManager::renderGameObjects(std::vector<GameObject*> gameObjects) {
		for (unsigned int i = 0; i < gameObjects.size(); i++) {
			for each (Renderer* renderer in gameObjects.at(i)->getComponents<Renderer>())
			{
				renderer->render(window);
			}
		}
	}

	void RenderManager::renderWindow()
	{
		for each (Camera* camera  in Camera::getActiveCameras()) {
			window->setView(camera->getView());
		}
		window->clear();

		auto gameObjects = MapManager::getInstance().get_aMap().getAllObjects();
		renderGameObjects(gameObjects);

		window->display();
	}

	void RenderManager::catchEvents()
	{
		while (window->pollEvent(events))
		{
			if (events.type == sf::Event::Resized)
			{
				for each (Camera* camera  in Camera::getActiveCameras()) {
					if (camera->getMatchSize()) {
						camera->setSize(window->getSize().x, window->getSize().y);
					}
				}
			}

			ControlInput::getInstantiate().catchEvents(events);
		}
	}

}
