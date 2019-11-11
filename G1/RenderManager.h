#pragma once

#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

#include <SFML\Graphics.hpp>

#include "Renderer.h"
#include "Properties.h"
#include "RenderProperties.h"
#include "MapManager.h"
#include "Camera.h"

namespace G1 {

	class RenderManager
	{
		friend class Engine;

		sf::Event events;


		RenderManager();

		void renderGameObjects(std::vector<GameObject*> gameObjects);
		void catchEvents();
		void renderWindow();

	public:
		sf::RenderWindow& getWindow();
		static RenderManager& getInstance() { static RenderManager instance; return instance; };
	};

}

#endif // !_RENDER_MANAGER_H_
