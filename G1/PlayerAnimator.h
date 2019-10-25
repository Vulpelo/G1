#pragma once

#include "Animator.h"

using namespace G1;

class PlayerAnimator : public Animator {
	/* Animations */
	Sprite idleSprite;
	Sprite runSprite;
	Sprite fallingSprite;
	
	SpriteAnimation idleAnimation;
	SpriteAnimation runAnimation;
	SpriteAnimation fallingAnimation;

	AnimationState idleState;
	AnimationState runState;
	AnimationState fallingState;

public:
	/* State variables */
	bool running = false;

	PlayerAnimator(Sprite& sprite) : Animator(sprite) {
		/* Creating Sprite and assigning the texture to it.
		This Sprite will be animated */
		idleSprite = Sprite(Assets::getInstance().getTexture("./assets/spritesheets/player-idle.png"), Vector2(33, 32));
		runSprite = Sprite(Assets::getInstance().getTexture("./assets/spritesheets/player-run.png"), Vector2(33, 32));
		fallingSprite = Sprite(Assets::getInstance().getTexture("./assets/spritesheets/player-jump.png"), Vector2(33, 32));

		/* Creating SpriteAnimation and asigning a copy of animationSprite*/
		idleAnimation = SpriteAnimation(idleSprite);
		idleAnimation.setProperties(0.2f, 3);

		runAnimation = SpriteAnimation(runSprite);
		runAnimation.setProperties(0.2f, 6);

		fallingAnimation = SpriteAnimation(fallingSprite);
		fallingAnimation.setProperties(0.5f, 2);
		fallingAnimation.setLooping(false);
		
		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {
			if (animator->getBool("running") && animator->getBool("grounded")) {
				animator->setState("run_1");
			}
			else if (!animator->getBool("grounded")) {
				animator->setState("fall_1");
			}
		});
		runState = AnimationState(runAnimation, [](Animator* animator)->void {
			if (!animator->getBool("running")) {
				animator->setState("idle_1");
			}
			else if (!animator->getBool("grounded")) {
				animator->setState("fall_1");
			}
		});
		fallingState = AnimationState(fallingAnimation, [](Animator* animator)->void {
			if (animator->getBool("grounded")) {
				animator->setState("idle_1");
			}
		});


		/* Adding states to animator. 
			First added state is a default one on start.*/
		this->addState("idle_1", idleState);
		this->addState("run_1", runState);
		this->addState("fall_1", fallingState);

		addBool("running", false);
		addBool("grounded", true);
	}
};
