#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"
#include "Camera.h"
#include "Sprite.h"
#include "Physics.h"

#include "GameMaster.h"

#include "GameObject002_Bullet.h"
#include "PlayerAnimator.h"
#include "IPlayerEnemyInteraction.h"


#include "resource.h"

using namespace G1;

class PlatformerPlayer :
	public GameObject, public IPlayerEnemyInteraction
{
	int health = 1;
	float enemyBonceVal = 80.0f;

	sf::Texture texture;

	Animator* animator;

	Vector2 actualMoveVelocity;
	Vector2 targetMoveVelocity;
	float maxSpeed = 100.f;
	float smoothMove = 0.05f;
	float speed = 500.0f;

	Vector2 gravity = Vector2(0.f, 500.f);

	bool grounded = false;
	bool climbing = false;

	bool canClimb = false;
	bool toJump = false;
	float jumpForce{ 10.f };
	bool crouched = false;

	bool lookingRight = true;

	Collider* crouchCollider = NULL;

	float shootingSpeed = 1.f;
	float a_shootingSpeed = 0.2f;
	bool s_keyPressed = false;

	bool changeColor = false;
	sf::Color color1 = sf::Color::Yellow;
	sf::Color color2 = sf::Color::Blue;
	bool aColor = false;

	ControlInput& c = ControlInput::getInstantiate();

	Renderer* rend = new RectangleRenderer(16, 16, color1);
	Rigidbody* rb = new Rigidbody();

	void movement();
	void shooting();
	void shapeShift();
	void animating();
	void flip();


public:
	PlatformerPlayer() { setTag("Player"); setLayer(Layer::PLAYER); }
	void startPlay();
	void beginPlay();
	void eventTick();

	void startOverlapping(GameObject* gameObject);
	void endOverlapping(GameObject* gameObject);

	void takeDamage(int damage);
	void bounce();
};

