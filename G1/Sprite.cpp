#include "Sprite.h"

namespace G1 {



	Sprite::Sprite(const sf::Texture& texture, const Vector2& imageSize)
		: texture(texture), imageSize(imageSize) 
	{
		this->texture = texture;
		this->imageSize = imageSize;
		sfSprite.setTexture(this->texture);
		sfSprite.setTextureRect(sf::IntRect(0, 0, this->imageSize.x, this->imageSize.y));
	}

	Sprite::Sprite(const sf::Texture& texture, const Vector2& imageSize, const Vector2& startPosition)
		: texture(texture), imageSize(imageSize), startPosition(startPosition)
	{
		this->startPosition = startPosition;
		this->imageSize = imageSize;
		this->texture = texture;

		sfSprite.setTexture(this->texture);
		sfSprite.setTextureRect(
			sf::IntRect(static_cast<int>(this->startPosition.x), static_cast<int>(this->startPosition.y),
				static_cast<int>(this->imageSize.x), static_cast<int>(this->imageSize.y)) );
	}

	void Sprite::render(sf::RenderWindow * w)
	{
		sfSprite.setPosition(getWorldPosition().x, getWorldPosition().y);
		sfSprite.setRotation(getWorldRotation());
		w->draw(sfSprite);
	}

	void Sprite::setTexture(sf::Texture texture) { 
		this->texture = texture; 
		sfSprite.setTexture(this->texture);
	}

	void Sprite::setStartPosition(const Vector2& startPosition) {
		this->startPosition = startPosition;

		sfSprite.setTextureRect(
			sf::IntRect(this->startPosition.x, this->startPosition.y,
				imageSize.x, imageSize.y));
	}

	void Sprite::setImageSize(const Vector2& imageSize) {
		this->imageSize = imageSize;

		sfSprite.setTextureRect(
			sf::IntRect(startPosition.x, startPosition.y,
				this->imageSize.x, this->imageSize.y));
	}

	void Sprite::setColor(sf::Color color)
	{
		sfSprite.setColor(color);
	}



}
