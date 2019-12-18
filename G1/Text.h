#pragma once

#ifndef _TEXT_H_
#define _TEXT_H_

#include "Renderer.h"

namespace G1 {

	class Text : public Renderer {
		friend class SpriteAnimation;

		const sf::Font* font;
		sf::Text text;

		void render(sf::RenderWindow& w);

	public:
		Text() {}
		/// <summary>
		/// Only for declaration as class's variable
		/// </summary>
		Text(const sf::Font& font, unsigned int textSize, const std::string string = "") {
			this->font = &font; 
			text.setCharacterSize(textSize);
			text.setFont(font);
			text.setString(string);
		}

		void setFont(const sf::Font& font);

		void setString(const std::string& textString);

		void setColor(sf::Color color);
	};

}

#endif // !_TEXT_H_
