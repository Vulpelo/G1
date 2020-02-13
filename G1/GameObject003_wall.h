#pragma once
#include "GameObject.h"
#include "RectangleCollider.h"
#include "RectangleRenderer.h"

using namespace G1;

class GameObject003_wall :
	public GameObject
{
	RectangleRenderer* rRend = NULL;
	sf::Color color1 = sf::Color::Red;
	sf::Color color2 = sf::Color::Green;

	float rectangleHeight = 60.0;
	float rectangleLength = 60.0;

	bool overlaps = false;
	bool overlappable = false;

public:
	GameObject003_wall() : GameObject() {};
	GameObject003_wall(float length, float height, bool overlappable) : GameObject() {
		rectangleLength = length;
		rectangleHeight = height;
		this->overlappable = overlappable;
	};

	void beginPlay();
	void eventTick();
	void startOverlapping(GameObject *overlaped);
	void isOverlaping(GameObject* overlaped);
	void endOverlapping(GameObject *overlaped);
};
