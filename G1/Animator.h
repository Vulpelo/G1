#pragma once

#include "SpriteAnimation.h"
#include "Component.h"


namespace G1 {

	class Animator : public Component {
		friend class RenderManager;

		float speed = 1.f;

		Sprite* sprite;

		SpriteAnimation actualAnimation;

		void mainEventTick();

	public:
		/// <summary>
		/// Animator needs a Sprite (Renderer) component connected to the same GameObject.
		/// Sprite will be modified to play animations
		/// </summary>
		Animator(Sprite& sprite) : Component::Component() { this->sprite = &sprite; }

		void addAnimation(const SpriteAnimation& animation);
	};

}
