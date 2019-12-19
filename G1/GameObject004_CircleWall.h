#pragma once
#include "GameObject.h"
#include "CircleRenderer.h"
#include "CircleCollider.h"
#include "Rigidbody.h"

using namespace G1;

class GameObject004_CircleWall :
	public G1::GameObject
{
	Rigidbody* rb = NULL;
	G1::CircleRenderer* rRend;
	sf::Color color1;
	sf::Color color2;

	Vector2 vel = Vector2(0, 0);
	bool overlaps;

public:
	GameObject004_CircleWall() {}
	GameObject004_CircleWall(const Vector2& vel) {
		this->vel = vel;
	}
	void beginPlay();
	void eventTick();
	void isOverlaping(GameObject* overlaped);
};

