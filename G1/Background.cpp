#include "Background.h"

Background::Background(const sf::Texture& texture, const Vector2& size)
{
	sprite = new Sprite(texture, size);
	addComponent(sprite);
}

void Background::eventTick()
{
}

// TODO: addComponent should handle deletion of components OR use smart pointers
