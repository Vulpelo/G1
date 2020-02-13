#pragma once

#include "GameObject.h"
#include "MapManager.h"
#include "Text.h"

using namespace G1;

class GameMaster : public GameObject {
	static int actualPoints;
	static Text* text;

public:
	static void setTextPoints(GameObject* textPoints);
	static void addPoints(int points);
	static void updatePointsText();
	static void restart();

	void beginPlay();
};
