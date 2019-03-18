#include "CircleRenderer.h"

namespace G1 {

	CircleRenderer::CircleRenderer()
	{
	}


	CircleRenderer::~CircleRenderer()
	{
	}

	CircleRenderer::CircleRenderer(double radiusT, sf::Color c)
		:radius(radiusT)
	{
		color = c;

		circle.setOrigin(sf::Vector2f(radius, radius));
		circle.setRadius(radius);
		circle.setPosition(transform.position.X, transform.position.Y);
		circle.setRotation(transform.rotationX);
		circle.setFillColor(color);
	}

	void CircleRenderer::render(sf::RenderWindow * w)
	{
		w->draw(circle);
	}

}
