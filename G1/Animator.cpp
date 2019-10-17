#include "Animator.h"

void G1::Animator::mainEventTick()
{
	sprite = &actualAnimation.actualSpriteFrame();
}

void G1::Animator::addAnimation(const SpriteAnimation & animation)
{
	actualAnimation = animation;
}
