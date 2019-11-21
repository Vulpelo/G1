#pragma once

#include "Sprite.h"
#include "GameObject.h"

using namespace G1;

class Background : public GameObject {

	Sprite* sprite = NULL;

public:
	Background();
	Background(const sf::Texture& texture, const Vector2& size);
	void startPlay();
	void eventTick();
};
