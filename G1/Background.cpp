#include "Background.h"

Background::Background(const sf::Texture& texture, const Vector2& size)
{
	sprite = Sprite(texture, size);
	addComponent(&sprite);
}
