#include "GameObject003_wall.h"


void GameObject003_wall::beginPlay()
{
	color1 = sf::Color::Red;
	color2 = sf::Color::Green;
	
	auto collidor = new RectangleCollider(rectangleLength, rectangleHeight, 0, 0);
	collidor->setOverlappable(overlappable);
	addComponent(collidor);

	if (!overlappable) {
		color1 = sf::Color::White;
	}
	rRend = new RectangleRenderer(rectangleLength, rectangleHeight, color1);
	addComponent(rRend);
}

void GameObject003_wall::eventTick()
{
	if (overlaps) {
		rRend->setColor(color2);
		overlaps = false;
	}
	else {
		rRend->setColor(color1);
	}
}



void GameObject003_wall::startOverlapping(GameObject *overlaped)
{
	//rRend->setColor(color2);
}

void GameObject003_wall::isOverlaping(GameObject *overlaped) {
	overlaps = true;
}


void GameObject003_wall::endOverlapping(GameObject *overlaped) 
{
	//rRend->setColor(color1);
}
