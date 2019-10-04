#pragma once
#include "GameObject.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"

using namespace G1;

class Ground01 :
	public GameObject
{
	RectangleRenderer* rRend = NULL;
	sf::Color color1 = sf::Color::White;

	float xLen = 50.0f;
	float yLen = 50.0f;

	bool overlaps = false;

public:
	Ground01() : GameObject() {};
	Ground01(float xLen, float yLen) : GameObject() {
		this->xLen = xLen;
		this->yLen = yLen;
	};

	void beginPlay();
};

