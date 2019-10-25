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
		circle.setPosition(getWorldPosition().x, getWorldPosition().y);
		circle.setRotation(getWorldRotation());
		circle.setFillColor(color);
	}

	void CircleRenderer::setColor(sf::Color color)
	{
		this->color = color;
		circle.setFillColor(color);
	}

	void CircleRenderer::render(sf::RenderWindow * w)
	{
		Vector2 pos = getWorldPosition();
		circle.setPosition(pos.x, pos.y);
		circle.setRotation(getWorldRotation());
		Vector2 scale = getWorldScale();
		circle.setScale(scale.x, scale.y);

		w->draw(circle);
	}

}
