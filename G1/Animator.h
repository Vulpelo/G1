#pragma once

#include "SpriteAnimation.h"
#include "Component.h"
#include <map>


namespace G1 {

	/* Uses State pattern */
	class Animator : public Component {
		friend class RenderManager;

		struct AnimationState {
			// Animation that is being played in this state
			SpriteAnimation spriteAnimation;

			AnimationState(const SpriteAnimation& animation) { this->spriteAnimation = animation; };
			// Checking all defined conditions
			//virtual SpriteAnimation changeConditions(const Animator& animator) {};
		};

		std::map<std::string, AnimationState> states;
		std::string actualState;

		struct Transition {
			SpriteAnimation targetAnimation;
			virtual SpriteAnimation changeConditions(const Animator& animator) = 0;
		};

		Transition* transition;
		SpriteAnimation changeCondition() { transition->changeConditions(*this); }

		
		float speed = 1.f;

		Sprite* sprite;

		void mainEventTick();

	public:
		/// <summary>
		/// Animator needs a Sprite (Renderer) component connected to the same GameObject.
		/// Sprite will be modified to play animations
		/// </summary>
		Animator(Sprite& sprite) : Component::Component() { this->sprite = &sprite; }

		/// <summary>
		/// adds new animation to empty state
		/// </summary>
		void addAnimation(const std::string& name, const SpriteAnimation& animation);

		/// <summary>
		/// Adds new sate
		/// </summary>
		void addState(const std::string& name, const AnimationState& animation);

		/// <summary>
		/// First state that will be played on start. 
		/// (By defalut first playing state will be one added first to Animator)
		/// </summary>
		/// <param name=""></param>
		void setStartState(const std::string& stateName);
	};

}
