#pragma once
// G1
#include "GameObject.h"
#include "CircleRenderer.h"
#include "RectangleRenderer.h"

#include "CircleCollider.h"
#include "RectangleCollider.h"

// Game
#include "GameObject002_Bullet.h"

using namespace G1;

class GameObject001 :
	public GameObject
{
	float speed;
	float rotationSpeed;
	float shootingSpeed;
	float a_shootingSpeed;
	bool s_keyPressed;
	bool changeColor;

	Renderer* rend;
	Rigidbody* rb;
	
	sf::Color color1;
	sf::Color color2;
	bool aColor;

	ControlInput c = ControlInput::getInstantiate();
public:
	void beginPlay();
	void eventTick();

private:
	void movement();
	void rotation();
	void shooting();
	void shapeShift();
};
