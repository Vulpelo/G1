#include "SquareUI.h"

void SquareUI::beginPlay()
{
	ContainerElement* conElement = new ContainerElement();
	conElement->setAnchor(anchor);
	addComponent(conElement);

	RectangleRenderer* rendRect = new RectangleRenderer(100, 100, sf::Color::Red);
	addComponent(rendRect);

	font.loadFromFile("./assets/fonts/Abalone.otf");
	Text* text = new Text(font, 15, "0");
	text->setColor(sf::Color::Black);
	addComponent(text);
}
