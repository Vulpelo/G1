#pragma once

#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

#include <SFML\Graphics.hpp>

#include "Renderer.h"
#include "Properties.h"
#include "MapManager.h"
#include "Camera.h"

namespace G1 {

	class RenderManager
	{
		sf::RenderWindow* window;
		void renderGameObjects(std::vector<GameObject*> gameObjects);

		RenderManager();

	public:
		~RenderManager();
		sf::RenderWindow& getWindow();
		static RenderManager& getInstance() { static RenderManager instance; return instance; };
		void renderWindow();
	};

}

#endif // !_RENDER_MANAGER_H_
