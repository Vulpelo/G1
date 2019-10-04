#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"

#include "GameObject002_Bullet.h"
#include "Physics.h"

using namespace G1;

class PlatformerPlayer :
	public GameObject
{
	Vector2 actualMoveVelocity;
	Vector2 targetMoveVelocity;
	float maxSpeed = 100.f;
	float smoothMove = 0.05f;
	float speed = 500.0f;

	bool grounded = false;

	float jumpForce = 10.f;

	float shootingSpeed = 1.f;
	float a_shootingSpeed = 0.2f;
	bool s_keyPressed = false;

	bool changeColor = false;
	sf::Color color1 = sf::Color::Yellow;
	sf::Color color2 = sf::Color::Blue;
	bool aColor = false;

	ControlInput c;

	Renderer* rend = new RectangleRenderer(40, 80, color1);
	Rigidbody* rb = new Rigidbody();

	void movement();
	void shooting();
	void shapeShift();

public:
	void beginPlay();
	void eventTick();
};

