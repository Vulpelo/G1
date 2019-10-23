#pragma once

#include "Sprite.h"

namespace G1 {

	class SpriteAnimation {
		friend class Animator;

		Sprite sprite;

		// Number of pixels to move by on x axis
		int pixelJump = 33;
		unsigned int amountOfFrames = 3;
		unsigned int actualFrame = 0;

		float speed = 1.0f;

		float timePerFrame = 0.2f;
		float actualTime = 0.f;

		Sprite actualSpriteFrame();

		SpriteAnimation() {}

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="sprite">Sprite that will be animated</param>
		SpriteAnimation(const Sprite& sprite) { this->sprite = sprite; }

		void play();
		void pause();
		void stop();

		/// <summary>
		/// Time after which next frame is going to show up
		/// </summary>
		/// <param name="time"></param>
		void setTimePerFrame(float time) { this->timePerFrame = time; }
	};

}
