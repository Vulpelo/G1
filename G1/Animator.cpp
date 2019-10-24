#include "Animator.h"

namespace G1 {

	void Animator::mainEventTick()
	{
		auto parentTmp = sprite->getParent();
		*sprite = states.at(actualState).nextFrame(this);
		sprite->setParent(parentTmp);
	}

	void Animator::addAnimation(const std::string& name, const SpriteAnimation& animation) {
		if (actualState.empty()) {
			actualState = name;
		}

		AnimationState animState(animation, [](Animator*) {});
		states.insert({ name, std::move(animState)});
	}

	void Animator::addState(const std::string& name, const AnimationState& animation) {
		if (actualState.empty()) {
			actualState = name;
		}
		states.insert({ name, animation});
	}

	void Animator::setState(const std::string& stateName) {
		this->actualState = stateName;
	}

}
