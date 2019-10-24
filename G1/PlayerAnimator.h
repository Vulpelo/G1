#pragma once

#include "Animator.h"

using namespace G1;

class PlayerAnimator : public Animator {
	/* Animations */
	sf::Texture idleTexture;
	sf::Texture runTexture;

	Sprite idleSprite;
	Sprite runSprite;
	
	SpriteAnimation idleAnimation;
	SpriteAnimation runAnimation;

	AnimationState idleState;
	AnimationState runState;

public:
	/* State variables */
	bool running = false;

	PlayerAnimator(Sprite& sprite) : Animator(sprite) {
		/*Loading a textures*/
		idleTexture.loadFromFile("./assets/spritesheets/player-idle.png");
		runTexture.loadFromFile("./assets/spritesheets/player-run.png");

		/* Creating Sprite and assigning the texture to it.
		This Sprite will be animated */
		idleSprite = Sprite(idleTexture, Vector2(33, 32));
		runSprite = Sprite(runTexture, Vector2(33, 32));

		/* Creating SpriteAnimation and asigning a copy of animationSprite*/
		idleAnimation = SpriteAnimation(idleSprite);
		idleAnimation.setProperties(0.2f, 3);

		runAnimation = SpriteAnimation(runSprite);
		runAnimation.setProperties(0.2f, 6);

		/* Creating states*/
		idleState = AnimationState(idleAnimation, [](Animator* animator)->void {
			if (animator->getVariable("running")) {
				animator->setState("run_1");
			}
		});
		runState = AnimationState(runAnimation, [](Animator* animator)->void {
			if (! animator->getVariable("running")) {
				animator->setState("idle_1");
			}
		});

		/* Adding states to animator. 
			First added state is a default one on start.*/
		this->addState("idle_1", idleState);
		this->addState("run_1", runState);

		setVariable("running", false);
	}
};
