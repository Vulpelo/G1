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
		static sf::RenderWindow * window;
		void renderGameObjects(std::vector<GameObject*> gameObjects);
	public:
		RenderManager();
		~RenderManager();
		static sf::RenderWindow*getWindow();
		void renderWindow();
	};

}

#endif // !_RENDER_MANAGER_H_
