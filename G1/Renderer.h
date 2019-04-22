#pragma once
#include "Component.h"
#include <SFML\Graphics.hpp>

namespace G1 {

	class Renderer : public Component
	{
		virtual void render(sf::RenderWindow * w) = 0;
	public:
		virtual void setColor(sf::Color color) = 0;
	};

}
