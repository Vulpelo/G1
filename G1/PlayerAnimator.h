#pragma once

#include "Animator.h"

using namespace G1;

class PlayerAnimator : public Animator {
	/* Animations */
	SpriteAnimation idleAnimation;
	SpriteAnimation runAnimation;
	SpriteAnimation fallingAnimation;
	SpriteAnimation crouchAnimation;
	SpriteAnimation climbAnimation;

	AnimationState idleState;
	AnimationState runState;
	AnimationState fallingState;
	AnimationState crouchState;
	AnimationState climbState;

public:

	PlayerAnimator(Sprite& sprite) : Animator(sprite) {
		/* Animator variables */
		{
			addBool("running", false);
			addBool("grounded", true);
			addBool("crouched", false);
			addBool("climbing", false);
			addBool("moving", false);
		}

		/* Creating SpriteAnimations 
			(instead creating from animationfrom scratch here, you can create class extended by SpriteAnimation that have setted properties) */
		idleAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("./assets/spritesheets/player-idle.png"), Vector2(33, 32)));
		idleAnimation.setProperties(0.2f, 3);

		runAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("./assets/spritesheets/player-run.png"), Vector2(33, 32)));
		runAnimation.setProperties(0.15f, 6);

		fallingAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("./assets/spritesheets/player-jump.png"), Vector2(33, 32)));
		fallingAnimation.setProperties(0.5f, 2);
		fallingAnimation.setLooping(false);

		crouchAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("./assets/spritesheets/player-crouch.png"), Vector2(33, 32)));
		crouchAnimation.setProperties(0.2f, 2);

		climbAnimation = SpriteAnimation(Sprite(Assets::getInstance().textures().get("./assets/spritesheets/player-climb.png"), Vector2(32, 32)));
		climbAnimation.setProperties(0.15f, 3);

		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {
			if (animator->getBool("running") && animator->getBool("grounded")) {
				animator->setState("run_1");
			}
			else if (!animator->getBool("grounded")) {
				animator->setState("fall_1");
			}
			else if (animator->getBool("crouched")) {
				animator->setState("crouch");
			}
			else if (animator->getBool("climbing")) {
				animator->setState("climb");
			}
		});
		runState = AnimationState(runAnimation, [](Animator* animator)->void {
			if (!animator->getBool("running")) {
				animator->setState("idle_1");
			}
			else if (!animator->getBool("grounded")) {
				animator->setState("fall_1");
			}
			else if (animator->getBool("crouched")) {
				animator->setState("crouch");
			}
		});
		fallingState = AnimationState(fallingAnimation, [](Animator* animator)->void {
			if (animator->getBool("grounded")) {
				animator->setState("idle_1");
			}
			else if (animator->getBool("climbing")) {
				animator->setState("climb");
			}
		});
		crouchState = AnimationState(crouchAnimation, [](Animator* animator)->void {
			if (!animator->getBool("crouched")) {
				if (animator->getBool("running")) {
					animator->setState("run_1");
				}
				else {
					animator->setState("idle_1");
				}
			}
			if (!animator->getBool("grounded")) {
				animator->setState("fall_1");
			}
		});
		climbState = AnimationState(climbAnimation, [](Animator* animator) {
			if (!animator->getBool("climbing")) {
				if (animator->getBool("grounded")) {
					animator->setState("idle_1");
				}
				else {
					animator->setState("fall_1");
				}
			}
			else {
				if (animator->getBool("moving")) {
					animator->play();
				}
				else {
					animator->pause();
				}
			}
		});

		/* Adding states to animator. 
			First added state is a default one on start.*/
		{
			this->addState("idle_1", idleState);
			this->addState("run_1", runState);
			this->addState("fall_1", fallingState);
			this->addState("crouch", crouchState);
			this->addState("climb", climbState);
		}
	}
};
