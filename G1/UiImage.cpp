#include "UiImage.h"

void UiImage::beginPlay()
{
	ContainerElement* conElement = new ContainerElement();
	conElement->setAnchor(Anchor::DOWN_LEFT);
	addComponent(conElement);

	RectangleRenderer* rendRect = new RectangleRenderer(100, 100, sf::Color::Red);
	addComponent(rendRect);
}
