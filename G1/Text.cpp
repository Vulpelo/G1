#include "Text.h"

void G1::Text::render(sf::RenderWindow & w)
{
	Vector2 pos = getWorldPosition();
	text.setPosition(pos.x, pos.y);
	text.setRotation(getWorldRotation());
	Vector2 scale = getWorldScale();
	text.setScale(scale.x, scale.y);
	text.setCharacterSize(50);
	w.draw(text);
}

void G1::Text::setFont(const sf::Font& font)
{
	this->font = &font;
	this->text.setFont(*this->font);
}

void G1::Text::setString(const std::string & textString)
{
	text.setString(textString);
}

void G1::Text::setColor(sf::Color color)
{
	text.setColor(color);
}
