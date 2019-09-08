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

		rRectangle.setOrigin(sf::Vector2f(length / 2.0f, height / 2.0f));
		rRectangle.setSize(sf::Vector2f(length, height));
		rRectangle.setPosition(transform.position.x + transform.position.x, transform.position.y + transform.position.y);
		rRectangle.setRotation(transform.rotationX + transform.rotationX);
		rRectangle.setFillColor(color);
	}

	void RectangleRenderer::setColor(sf::Color color)
	{
		this->color = color;
		rRectangle.setFillColor(color);
	}

	void RectangleRenderer::render(sf::RenderWindow * w)
	{
		rRectangle.setPosition(getWorldPosition().x, getWorldPosition().y);
		rRectangle.setRotation(getWorldRotation());
		w->draw(rRectangle);
	}

}
