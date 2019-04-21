#pragma once
// G1
#include "GameObject.h"
#include "CircleRenderer.h"
#include "RectangleRenderer.h"

#include "CollisionCircle.h"
#include "CollisionRectangle.h"

// Game
#include "GameObject002_Bullet.h"

using namespace G1;

class GameObject001 :
	public GameObject
{
	float speed;
	float shootingSpeed;
	float a_shootingSpeed;
	bool s_keyPressed;
	bool changeColor;

	CircleRenderer* circleRend;
	
	sf::Color color1;
	sf::Color color2;
	bool aColor;

	ControlInput c;
public:
	void beginPlay();
	void eventTick();

private:
	void movement();
	void shooting();
	void shapeShift();
};
