#pragma once

#ifndef _RECTANGLE_RENDERER_H_
#define _RECTANGLE_RENDERER_H_

#include "Renderer.h"
#include "Rectangle.h"

namespace G1 {

	class RectangleRenderer : public Renderer
	{
		float length = 10.f, height = 10.f;
		sf::RectangleShape rRectangle;
		sf::Color color;

		void render(sf::RenderWindow&);
	public:
		RectangleRenderer();
		RectangleRenderer(float leng, float heig, sf::Color c);
		void setColor(sf::Color color);
		~RectangleRenderer();
	};

}

#endif // !_RECTANGLE_RENDERER_H_
