#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Component.h"
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Sprite.hpp>

namespace G1 {

	class Renderer : public Component, public Transformable
	{
		friend class RenderManager;

		virtual void render(sf::RenderWindow& w) = 0;
	public:
		virtual void setColor(sf::Color color) = 0;
	};

}

#endif // !_RENDERER_H_
