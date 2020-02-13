#pragma once

#include "Animator.h"

using namespace G1;

class EagleAnimator : public Animator {
	/* Animations */
	SpriteAnimation idleAnimation;

	AnimationState idleState;

public:

	EagleAnimator(Sprite& sprite) : Animator(sprite) {
		/* Creating SpriteAnimations
			(instead creating from animationfrom scratch here, you can create class extended by SpriteAnimation that have setted properties) */
		idleAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("eagle"), Vector2(40, 41)));
		idleAnimation.setProperties(0.15f, 4);

		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {});

		/* Adding states to animator.
			First added state is a default one on start.*/
		{
			this->addState("idle_1", idleState);
		}
	}
};
