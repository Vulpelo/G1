#include "GameObject003_wall.h"


void GameObject003_wall::beginPlay()
{
	overlaps = false;

	color1 = sf::Color::Red;
	color2 = sf::Color::Green;
	
	rRend = new RectangleRenderer(60 ,60, color1);
	addComponent(rRend);

	auto collidor = new RectangleCollider(60, 60, 0, 0);
	addComponent(collidor);
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



void GameObject003_wall::startOverlaping(GameObject *overlaped)
{
	//rRend->setColor(color2);
}

void GameObject003_wall::isOverlaping(GameObject *overlaped) {
	overlaps = true;
}


void GameObject003_wall::endOverlaping(GameObject *overlaped) 
{
	//rRend->setColor(color1);
}
