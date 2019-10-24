#pragma once

#include "SpriteAnimation.h"
#include "Component.h"

#include <map>

namespace G1 {

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

		/// <summary> Creates or assings new value to boolean under given name</summary>
		void addBool(std::string name, bool value) { boolList[name] = value; };
		/// <summary> Creates or assings new value to float under given name </summary>
		void addFloat(std::string name, float value) { floatList[name] = value; };
		/// <summary> Creates or assings new value to integer under given name </summary>
		void addInt(std::string name, int value) { intList[name] = value; };

		/// <summary>
		/// adds new animation to new empty state
		/// </summary>
		void addAnimation(const std::string& name, const SpriteAnimation& animation);
		/// <summary> Adds new sate </summary>
		void addState(const std::string& name, const AnimationState& animation);

	private:
		std::map<std::string, AnimationState> states;
		std::string actualState;
		
		std::map<std::string, bool> boolList;
		std::map<std::string, int> intList;
		std::map<std::string, float> floatList;

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
		/// First state that will be played on start. 
		/// (By defalut first playing state will be one added first to Animator)
		/// </summary>
		void setState(const std::string& stateName);

		/// <summary>
		/// Sets value of boolean 
		/// </summary>
		void setBool(std::string name, bool value) { boolList.at(name) = value; };
		bool getBool(std::string name) const { return boolList.at(name); }

		/// <summary>
		/// Sets value of float
		/// </summary>
		void setFloat(std::string name, float value) { floatList.at(name) = value; };
		float getFloat(std::string name) const { return floatList.at(name); }

		/// <summary>
		/// Sets value of integer
		/// </summary>
		void setInt(std::string name, int value) { intList.at(name) = value; };
		int getInt(std::string name) const { return intList.at(name); }
	};

}
