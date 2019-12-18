#pragma once

#include "Sprite.h"
#include "GameObject.h"
#include "Camera.h"

#include "IPrefab.h"

using namespace G1;

class Background : public GameObject {

	Sprite* sprite = NULL;
	Vector2 startPos;
	Vector2 offset = Vector2(500.f, -100.f);
	float lerpTime = 0.f;

public:
	Background();
	Background(const G1::prefabArgs & args);
	Background(const sf::Texture& texture, const Vector2& size);
	void startPlay();
	void beginPlay();
	void eventTick();
};
