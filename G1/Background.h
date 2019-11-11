#pragma once

#include "Sprite.h"
#include "GameObject.h"

using namespace G1;

class Background : public GameObject {

	Sprite sprite;

public:
	Background(const sf::Texture& texture, const Vector2& size);
};
