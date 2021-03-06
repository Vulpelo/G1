#pragma once

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Renderer.h"

namespace G1 {

	class Sprite : public Renderer {
		friend class SpriteAnimation;

		Vector2 startPosition;
		Vector2 imageSize;

		const sf::Texture* texture;
		
		sf::Sprite sfSprite;

		void render(sf::RenderWindow& w);


	public:
		/// <summary>
		/// Only for declaration as class's variable
		/// </summary>
		Sprite() {}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="texture"></param>
		/// <param name="imageSize"> Size of sprite. Doesn't change size of texture. If sprite is smaller than texture then texture is cropped.  </param>
		Sprite(const sf::Texture& texture, const Vector2& imageSize = Vector2(50, 50));
		Sprite(const sf::Texture& texture, const Vector2& imageSize, const Vector2& startPosition);

		void setTexture(const sf::Texture& texture);

		Vector2 getStartPosition() const { return startPosition; };
		const Vector2& getStartPosition() { return startPosition; };
		void setStartPosition(const Vector2& startPosition);
		
		void setImageSize(const Vector2& imageSize);
		Vector2 getImageSize() const { return imageSize; }

		void setColor(sf::Color color);
	};

}

#endif // !_SPRITE_H_
