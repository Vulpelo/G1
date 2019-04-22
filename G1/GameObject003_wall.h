#pragma once
#include "GameObject.h"
#include "RectangleCollider.h"
#include "RectangleRenderer.h"

using namespace G1;

class GameObject003_wall :
	public GameObject
{
	RectangleRenderer* rRend;
	sf::Color color1;
	sf::Color color2;

	bool overlaps;

public:
	void beginPlay();
	void eventTick();
	void startOverlaping(GameObject *overlaped);
	void isOverlaping(GameObject* overlaped);
	void endOverlaping(GameObject *overlaped);
};
