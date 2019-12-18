#pragma once

#include "GameObject.h"
#include "Text.h"

using namespace G1;

class GameMaster : public GameObject {
	static int actualPoints;
	static Text* text;

public:
	static void setTextPoints(GameObject* textPoints);
	static void addPoints(int points);
	static void updatePointsText();

	void beginPlay();
};
