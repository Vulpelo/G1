#pragma once

#include "Renderer.h"

namespace G1 {

	class Sprite : public Renderer {
		friend class SpriteAnimation;

		Vector2 startPosition;
		Vector2 imageSize;

		sf::Texture texture;
		
		sf::Sprite sfSprite;

		void render(sf::RenderWindow * w);

		Sprite() {}

	public:
		Sprite(const sf::Texture& texture, const Vector2& imageSize);

		Sprite(const sf::Texture& texture, const Vector2& imageSize, const Vector2& startPosition);

		void setTexture(const sf::Texture& texture);
		void setStartPosition(const Vector2& startPosition);
		void setImageSize(const Vector2& imageSize);
		
		void setColor(sf::Color color);
	};

}
