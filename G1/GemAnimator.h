#pragma once

#include "Animator.h"

using namespace G1;

class GemAnimator : public Animator {
	/* Animations */
	SpriteAnimation idleAnimation;

	AnimationState idleState;

public:

	GemAnimator(Sprite& sprite) : Animator(sprite) {
		/* Creating SpriteAnimations
			(instead creating from animationfrom scratch here, you can create class extended by SpriteAnimation that have setted properties) */
		idleAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("gem"), Vector2(15, 13)));
		idleAnimation.setProperties(0.15f, 5);

		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {});

		/* Adding states to animator.
			First added state is a default one on start.*/
		{
			this->addState("idle_1", idleState);
		}
	}
};
