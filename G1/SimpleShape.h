#pragma once

#ifndef _SIMPLE_SHAPE_H_
#define _SIMPLE_SHAPE_H_

#include <SFML\Graphics.hpp>
#include "MathFunctions.h"
#include "Transform.h"

namespace G1 {

	class SimpleShape
	{
	protected:
		Transform transform;

	public:
		SimpleShape();

		/*=Transform=*/
		void setPosition(float aX, float aY);
		void setTransform(Transform transform);
		Transform getTransform();

		//rotation
		float getRotation();
		void setRotation(float x);
	};

}

#endif // !_SIMPLE_SHAPE_H_
