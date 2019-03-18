#pragma once

#include <SFML\Graphics.hpp>
#include "MathFunctions.h"
#include "Transform.h"
//#include "GameObject.h"

namespace G1 {

	class SimpleShape
	{
	protected:
		//GameObject* parent;
		Transform transform;

		// Color of the shape
		//sf::Color color;

	public:
		SimpleShape();
		//SimpleShape(sf::Color c);
		//virtual void draw(sf::RenderWindow * w) = 0;

		//void setParent(GameObject* parent);

		/*=Transform=*/
		void setPosition(float aX, float aY);
		void setTransform(Transform transform);
		Transform getTransform();

		//rotation
		float getRotation();
		void setRotation(float x);
	};

}
