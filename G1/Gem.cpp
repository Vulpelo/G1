#include "Gem.h"

void Gem::startPlay()
{
	Sprite* sprite = new Sprite();
	addComponent(sprite);

	GemAnimator* animator = new GemAnimator(*sprite);
	addComponent(animator);

	CircleCollider* collider = new CircleCollider(10.f, 0, 0);
	collider->setOverlappable(true);
	addComponent(collider);
}

void Gem::startOverlapping(GameObject * other)
{
	if (other->isLayer(Layer::PLAYER)) {
		destroy();
		GameMaster::addPoints(1);
	}
}
