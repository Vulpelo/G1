#pragma once

#include <SFML\Graphics.hpp>

namespace G1 {

	class RenderProperties {
		friend class RenderManager;

		static sf::RenderWindow* window;

		static void setWindow(sf::RenderWindow* nWindow) { if (window) delete window;  window = nWindow; }

	public:
		static sf::RenderWindow& getWindow() { return *window; };

		~RenderProperties();
	};

}

