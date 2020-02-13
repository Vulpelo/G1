#pragma once

#include "Animator.h"

using namespace G1;

class OposumAnimator : public Animator {
	/* Animations */
	SpriteAnimation idleAnimation;
	SpriteAnimation deathAnimation;

	AnimationState idleState;
	AnimationState deathState;

public:

	OposumAnimator(Sprite& sprite) : Animator(sprite) {
		/* Variables */
		{
			addBool("dead", false);
		}

		/* Creating SpriteAnimations
			(instead creating from animationfrom scratch here, you can create class extended by SpriteAnimation that have setted properties) */
		idleAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("oposum"), Vector2(36, 28)));
		idleAnimation.setProperties(0.15f, 6);

		deathAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("enemy-death"), Vector2(40, 41)));
		deathAnimation.setProperties(0.15f, 6);
		deathAnimation.setLooping(false);

		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {
			if (animator->getBool("dead")) {
				animator->setState("death");
			}
		});
		deathState = AnimationState(deathAnimation, [](Animator* animator)->void {});

		/* Adding states to animator.
			First added state is a default one on start.*/
		{
			this->addState("idle_1", idleState);
			this->addState("death", deathState);
		}
	}
};
