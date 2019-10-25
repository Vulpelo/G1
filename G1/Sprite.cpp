#include "Sprite.h"

namespace G1 {

	Sprite::Sprite(const sf::Texture& texture, const Vector2& imageSize)
		: texture(&texture), imageSize(imageSize) 
	{
		sf::Vector2u vecU = texture.getSize();
		this->texture = &texture;
		this->imageSize = imageSize;

		sfSprite.setTexture(*this->texture);
		sfSprite.setTextureRect(sf::IntRect(0, 0, this->imageSize.x, this->imageSize.y));
		
		sfSprite.setOrigin(this->imageSize.x/2.f, this->imageSize.y/2.f);
	}

	Sprite::Sprite(const sf::Texture& texture, const Vector2& imageSize, const Vector2& startPosition)
		: texture(&texture), imageSize(imageSize), startPosition(startPosition)
	{
		this->startPosition = startPosition;
		this->imageSize = imageSize;
		this->texture = &texture;

		sfSprite.setTexture(*this->texture);
		sfSprite.setTextureRect(
			sf::IntRect(static_cast<int>(this->startPosition.x), static_cast<int>(this->startPosition.y),
				static_cast<int>(this->imageSize.x), static_cast<int>(this->imageSize.y)) );

		sfSprite.setOrigin(this->imageSize.x / 2.f, this->imageSize.y / 2.f);
	}

	void Sprite::render(sf::RenderWindow * w)
	{
		Vector2 pos = getWorldPosition();
		sfSprite.setPosition(pos.x, pos.y);
		sfSprite.setRotation(getWorldRotation());
		Vector2 scale = getWorldScale();
		sfSprite.setScale(scale.x, scale.y);
		
		w->draw(sfSprite);
	}

	void Sprite::setTexture(const sf::Texture& texture) { 
		this->texture = &texture; 
		sfSprite.setTexture(*this->texture);

		if (this->imageSize.equal(Vector2(0, 0))) {
			sf::Vector2u vecU = texture.getSize();
			sfSprite.setOrigin(vecU.x / 2.f, vecU.y / 2.f);
		}
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
