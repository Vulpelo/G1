#include "GameObject004_CircleWall.h"

void GameObject004_CircleWall::beginPlay()
{
	overlaps = false;

	color1 = sf::Color::Red;
	color2 = sf::Color::Green;

	rRend = new CircleRenderer(30, color1);
	addComponent(rRend);

	auto collidor = new CollisionCircle(30, 0, 0);
	addComponent(collidor);
}

void GameObject004_CircleWall::eventTick()
{
	if (overlaps) {
		rRend->setColor(color2);
		overlaps = false;
	}
	else {
		rRend->setColor(color1);
	}
}

void GameObject004_CircleWall::isOverlaping(GameObject * overlaped)
{
	overlaps = true;
}
