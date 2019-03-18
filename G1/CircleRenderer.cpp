#include "CircleRenderer.h"

namespace G1 {

	CircleRenderer::CircleRenderer()
	{
	}


	CircleRenderer::~CircleRenderer()
	{
	}

	CircleRenderer::CircleRenderer(float radiusT, sf::Color c)
		:radius(radiusT)
	{
		color = c;

		circle.setOrigin(sf::Vector2f(radius, radius));
		circle.setRadius(radius);
		circle.setPosition(getWorldPosition().X, getWorldPosition().Y);
		circle.setRotation(getWorldRotation());
		circle.setFillColor(color);
	}

	void CircleRenderer::render(sf::RenderWindow * w)
	{
		circle.setPosition(getWorldPosition().X, getWorldPosition().Y);
		circle.setRotation(getWorldRotation());
		w->draw(circle);
	}

}
