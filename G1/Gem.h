#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "RectangleRenderer.h"
#include "RectangleCollider.h"
#include "Camera.h"
#include "Sprite.h"
#include "Physics.h"
#include "GameMaster.h"

#include "GemAnimator.h"

#include "resource.h"

using namespace G1;

class Gem :
	public GameObject
{
public:
	void startPlay();
	void startOverlapping(GameObject* other);
};
