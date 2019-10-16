#include "RenderManager.h"

namespace G1 {

	sf::RenderWindow* RenderManager::window = NULL;

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
			for each (Renderer* renderer in gameObjects.at(i)->getComponents<Renderer>())
			{
				renderer->render(window);
			}
	}

	void RenderManager::renderWindow()
	{
		sf::FloatRect ff = sf::FloatRect(200.f, 300.f, 400.f, 300.f);
		ff.left = 200.f;
		ff.top = 300.f;

		sf::View view(ff);
		
		window->setView(view);


		for each (Camera* camera  in Camera::getActiveCameras())
		{
			auto cc = camera->getView();
			window->setView(cc);
		}

		window->clear();

		auto gameObjects = MapManager::get_aMap()->getAllObjects();

		renderGameObjects(gameObjects);

		window->display();
	}

}
