#pragma once

#include "Sprite.h"

namespace G1 {

	class SpriteAnimation {
		friend class Animator;

		Sprite sprite;

		// Number of pixels to move by on x axis
		int pixelJump = 100;
		unsigned int amountOfFrames = 1;
		unsigned int actualFrame = 0;

		float speed = 1.0f;

		float timePerFrame = 0.2f;
		float actualTime = 0.f;

		bool looping = true;

		Sprite actualSpriteFrame();

	public:
		SpriteAnimation() {}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="sprite">Sprite that will be animated</param>
		SpriteAnimation(const Sprite& sprite) { this->sprite = sprite; pixelJump = lround( sprite.getImageSize().x ); }

		void restart() { actualFrame = 0; actualTime = 0.f; }
		void play();
		void pause();
		void stop();

		/// <summary>
		/// Time after which next frame is going to show up
		/// </summary>
		/// <param name="time"></param>
		void setTimePerFrame(float time) { this->timePerFrame = time; }

		void setAmountOfFrames(unsigned int amount) { this->amountOfFrames = amount; };

		/// <summary>
		/// Amount of pixels that animation need to move for the next frame.
		/// By default pixel jump equals sprite's width.
		/// </summary>
		/// <param name="pixelJump"></param>
		void setPixelJump(int pixelJump) { this->pixelJump = pixelJump; }

		void setLooping(bool looping) { this->looping = looping; }

		void setProperties(float timePerFrame, unsigned int amountOfFrames, int pixelJump=0);
	};

}
