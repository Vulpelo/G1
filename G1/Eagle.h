#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"
#include "Camera.h"
#include "Sprite.h"
#include "Physics.h"

#include "EagleAnimator.h"
#include "IPlayerEnemyInteraction.h"

#include "resource.h"

using namespace G1;

class Eagle :
	public GameObject
{
	Transformable* target = NULL;
	Rigidbody* rb;
	float speed = 60.0f;
	float seeRadious = 150.0f;
	float damage = 99;

	Vector2 startPosition;
	float distancePrecision = 5.f;

public:
	Eagle(Transformable* target) : target(target) {};
	void startPlay();
	void eventTick();
	void fixedEventTick();

	void startOverlapping(GameObject* oGameObject);
};
