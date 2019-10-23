#include "SpriteAnimation.h"

namespace G1 {

	Sprite G1::SpriteAnimation::actualSpriteFrame()
	{
		actualTime += Time::getDeltaTime();

		Vector2 pos = sprite.getStartPosition();
		
		int jumps = actualTime / timePerFrame;
		actualTime = actualTime - jumps*timePerFrame;

		actualFrame = (jumps + actualFrame) % amountOfFrames;
		pos.x = actualFrame * pixelJump;

		sprite.setStartPosition( pos );
		return sprite;
	}

}
