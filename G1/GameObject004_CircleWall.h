#pragma once
#include "GameObject.h"
#include "CircleRenderer.h"
#include "CircleCollider.h"

using namespace G1;

class GameObject004_CircleWall :
	public G1::GameObject
{
	G1::CircleRenderer* rRend;
	sf::Color color1;
	sf::Color color2;

	bool overlaps;

public:
	void beginPlay();
	void eventTick();
	void isOverlaping(GameObject* overlaped);
};

