#pragma once

#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML\Graphics.hpp>

#include "Properties.h"
#include "MapManager.h"

namespace G1 {

	class RenderManager
	{
		static sf::RenderWindow * window;
		void renderGameObjects(std::vector<GameObject*> gameObjects);
	public:
		RenderManager();
		~RenderManager();
		static sf::RenderWindow*getWindow();
		void renderWindow();
	};

}

#endif // !RENDER_MANAGER_H
