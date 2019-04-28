#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Transform.h"
#include "Transformable.h"

namespace G1 {

	class Component
	{
		friend class GameObject;
		std::vector <Component *> newOverlapingComponents;

		virtual void mainEventTick();

	protected:
		//overlaping
		char* name;
		std::vector <Component *> overlapingComponents;

	public:
		Component();

		void setName(char* name);
		char* getName() const;

		void addOverlapComponent(Component*);

		virtual void setRotateToMovementDirection(bool a) {};
		// virtual bool getRotateToMovementDirection() = 0;

		virtual void render(sf::RenderWindow *) {};

		//void overlapingEndMain();
		~Component();
	};

}

#endif // !_COMPONENT_H_
