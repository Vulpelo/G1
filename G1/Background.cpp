#include "Background.h"

Background::Background() {
	sprite = new Sprite(Assets::getInstance().textures().get("./assets/environment/layers/back.png"), 
		Vector2(384, 240));
}

Background::Background(const sf::Texture& texture, const Vector2& size)
{
	sprite = new Sprite(texture, size);
}

void Background::startPlay() {
	addComponent(sprite);
}

void Background::eventTick()
{
}

// TODO: addComponent should handle deletion of components OR use smart pointers
