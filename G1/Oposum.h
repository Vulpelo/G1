#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"
#include "Camera.h"
#include "Sprite.h"
#include "Physics.h"

#include "IPlayerEnemyInteraction.h"
#include "OposumAnimator.h"

#include "resource.h"

using namespace G1;

class Oposum :
	public GameObject
{
	Rigidbody* rb;
	OposumAnimator* animator = NULL;

	float checkDistance = 15.f;
	float speed = 60.0f;
	int dir = 1;

	int damage = 1;

	bool dead = false;

public:
	void startPlay();
	void eventTick();
	void fixedEventTick();
	void startOverlapping(GameObject* otherGameObject);
};
