#pragma once
#include "Renderer.h"
#include "Rectangle.h"

namespace G1 {

	class RectangleRenderer : public Renderer
	{
		float length, height;
		sf::RectangleShape rRectangle;
		sf::Color color;

		void render(sf::RenderWindow*);
	public:
		RectangleRenderer();
		RectangleRenderer(float leng, float heig, sf::Color c);
		~RectangleRenderer();
	};

}
