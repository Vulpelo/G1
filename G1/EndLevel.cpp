#include "EndLevel.h"

void EndLevel::startPlay()
{
	RectangleCollider* collider = new RectangleCollider(x, y);
	collider->setOverlappable(true);
	addComponent(collider);
}

void EndLevel::startOverlapping(GameObject * oGameObject)
{
	if (oGameObject->isLayer(Layer::PLAYER)) {
		MapManager::getInstance().loadMap(nextLevelName);
	}
}
