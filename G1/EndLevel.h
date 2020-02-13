#pragma once

#include "RectangleCollider.h"
#include "GameObject.h"

#include "MapManager.h"

using namespace G1;

class EndLevel : public GameObject {
	std::string nextLevelName;
	float x = 10, y = 10;

public:
	EndLevel(const std::string& nextLevelName, float x, float y) : nextLevelName(nextLevelName), x(x), y(y) {};
	void startPlay();
	void startOverlapping(GameObject* oGameObject);
};