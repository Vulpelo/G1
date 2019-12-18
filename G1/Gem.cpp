#include "Gem.h"

void Gem::startPlay()
{
	Sprite* sprite = new Sprite();
	addComponent(sprite);

	GemAnimator* animator = new GemAnimator(*sprite);
	addComponent(animator);
}
