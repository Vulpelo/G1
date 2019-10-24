#pragma once

#include "SpriteAnimation.h"
#include "Component.h"

#include <map>

namespace G1 {

	/* Uses State pattern */
	class Animator : public Component {
		friend class RenderManager;

	protected:
		struct AnimationState {
			//virtual SpriteAnimation changeConditions(const Animator& animator) {};
			void(*fun)(Animator* animator) = [](Animator* animator) {};

			// Animation that is being played in this state
			SpriteAnimation spriteAnimation;

			AnimationState() {}
			AnimationState(const SpriteAnimation& animation) { this->spriteAnimation = animation; };
			
			template<typename T>
			AnimationState(const SpriteAnimation& animation, T&& conditionHandler) { 
				this->spriteAnimation = animation; 
				fun = conditionHandler;
			};
			
			// Checking all defined conditions
			Sprite nextFrame(Animator* animator) {
				fun(animator);
				return spriteAnimation.actualSpriteFrame();
			}
		};
	private:
		std::map<std::string, AnimationState> states;
		std::string actualState;
		
		std::map<std::string, bool> variableList;

		float speed = 1.f;

		Sprite* sprite;

		void mainEventTick();
	public:
		Animator() {}
		/// <summary>
		/// Animator needs a Sprite (Renderer) component connected to the same GameObject.
		/// Sprite will be modified to play animations
		/// </summary>
		Animator(Sprite& sprite) : Component::Component() { this->sprite = &sprite; }

		/// <summary>
		/// adds new animation to new empty state
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
		void setState(const std::string& stateName);

		void setVariable(std::string name, bool value) {
			variableList.insert_or_assign(name, value);
		};

		bool getVariable(std::string name) {
			return variableList.at(name);
		};
	};

}
