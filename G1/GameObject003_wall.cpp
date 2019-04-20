#include "GameObject003_wall.h"


void GameObject003_wall::beginPlay()
{
	RectangleRenderer* cRend = new RectangleRenderer(30 ,30, sf::Color::Red);

	addComponent(cRend);
}
