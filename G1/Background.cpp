#include "Background.h"

Background::Background(const sf::Texture& texture, const Vector2& size)
{
	sprite = Sprite(texture, size);
	addComponent(&sprite);
}

// TODO: addComponent should handle deletion of components OR use smart pointers
