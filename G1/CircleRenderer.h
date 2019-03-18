#pragma once
#include "Renderer.h"

namespace G1 {

	class CircleRenderer : public Renderer
	{
		sf::CircleShape circle;
		sf::Color color;
		float radius;
		void render(sf::RenderWindow*);
	public:
		CircleRenderer();
		CircleRenderer(double radiusTemp, sf::Color);
		~CircleRenderer();
	};

}
