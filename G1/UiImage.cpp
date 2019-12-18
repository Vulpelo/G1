#include "UiImage.h"

void UiImage::beginPlay()
{
	ContainerElement* conElement = new ContainerElement();
	conElement->setAnchor(Anchor::UP_LEFT);
	addComponent(conElement);

	//RectangleRenderer* rendRect = new RectangleRenderer(100, 100, sf::Color::Red);
	//addComponent(rendRect);
	font.loadFromFile("./assets/fonts/Abalone.otf");
	Text* text = new Text(font, 15, "0");
	text->setColor(sf::Color::Black);
	addComponent(text);

	GameMaster::setTextPoints(this);
}
