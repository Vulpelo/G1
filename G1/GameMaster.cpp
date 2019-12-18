#include "GameMaster.h"

int GameMaster::actualPoints = 0;
Text* GameMaster::text = NULL;

void GameMaster::setTextPoints(GameObject * textPoints)
{
	text = textPoints->getComponent<Text>();
}

void GameMaster::addPoints(int points)
{
	actualPoints += points;
	updatePointsText();
}

void GameMaster::updatePointsText()
{
	text->setString(std::to_string(actualPoints));
}

void GameMaster::beginPlay()
{
}
