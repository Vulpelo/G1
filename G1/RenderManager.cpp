#include "RenderManager.h"

namespace G1 {

	RenderManager::RenderManager()
	{
		RenderProperties::setWindow(
			new sf::RenderWindow(sf::VideoMode(Properties::width, Properties::height, Properties::bitPerPixel),
				"G1",
				sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize)
		);
	}

	sf::RenderWindow& RenderManager::getWindow()
	{
		return RenderProperties::getWindow();
	}

	void RenderManager::renderGameObjects(std::vector<GameObject*> gameObjects) {
		for (unsigned int i = 0; i < gameObjects.size(); i++) {
			for each (Renderer* renderer in gameObjects.at(i)->getComponents<Renderer>())
			{
				if (renderer->isEnabled()) {
					renderer->render(getWindow());
				}
			}
		}
	}

	void RenderManager::renderWindow()
	{
		for each (Camera* camera  in Camera::getActiveCameras()) {
			getWindow().setView(camera->getView());
		}
		getWindow().clear();

		auto gameObjects = MapManager::getInstance().get_aMap().getAllObjects();
		renderGameObjects(gameObjects);

		getWindow().display();
	}

	void RenderManager::catchEvents()
	{
		while (getWindow().pollEvent(events))
		{
			if (events.type == sf::Event::Resized)
			{
				for each (Camera* camera  in Camera::getActiveCameras()) {
					if (camera->getMatchSize()) {
						camera->setSize(
							static_cast<float>(getWindow().getSize().x), 
							static_cast<float>(getWindow().getSize().y));
					}
				}
			}

			ControlInput::getInstantiate().catchEvents(events);
		}
	}

}
