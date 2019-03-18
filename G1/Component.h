#pragma once

#ifndef _Component_H_
#define _Component_H_

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Transform.h"
#include "Transformable.h"

namespace G1 {

	class Component : public Transformable
	{
		friend class PhysicsHandle;

		std::vector <Component *> newOverlapingComponents;

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

#endif // !_Component_H_
