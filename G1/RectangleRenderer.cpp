#include "RectangleRenderer.h"

namespace G1 {

	RectangleRenderer::RectangleRenderer()
	{
	}


	RectangleRenderer::~RectangleRenderer()
	{
	}

	RectangleRenderer::RectangleRenderer(float leng, float heig, sf::Color c)
		: length(leng), height(heig)
	{
		color = c;

		rRectangle.setOrigin(sf::Vector2f(length / 2.0, height / 2.0));
		rRectangle.setSize(sf::Vector2f(length, height));
		rRectangle.setFillColor(color);
		rRectangle.setPosition(transform.position.X + transform.position.X, transform.position.Y + transform.position.Y);
		rRectangle.setRotation(transform.rotationX + transform.rotationX);
	}

	void RectangleRenderer::render(sf::RenderWindow * w)
	{
		w->draw(rRectangle);
	}

}
