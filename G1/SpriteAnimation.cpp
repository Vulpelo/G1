#include "SpriteAnimation.h"

namespace G1 {

	Sprite G1::SpriteAnimation::actualSpriteFrame()
	{
		if (!paused) {
			actualTime += Time::getDeltaTime();

			Vector2 pos = sprite.getStartPosition();
		
			int jumps = static_cast<int>(actualTime / timePerFrame);
			actualTime = actualTime - jumps*timePerFrame;

			actualFrame = (jumps + actualFrame) % amountOfFrames;
		
			if (!looping && (jumps + actualFrame) >= amountOfFrames-1) {
				actualFrame = amountOfFrames - 1;
			}
		
			pos.x = static_cast<float>(actualFrame * pixelJump);

			sprite.setStartPosition( pos );
		}
		return sprite;
	}

	void SpriteAnimation::setProperties(float timePerFrame, unsigned int amountOfFrames, int pixelJump)
	{
		setTimePerFrame(timePerFrame);
		setAmountOfFrames(amountOfFrames);
		if (pixelJump != 0) {
			setPixelJump(pixelJump);
		}
	}

}
