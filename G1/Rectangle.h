#pragma once

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "SimpleShape.h"

namespace G1 {

	class Rectangle : public SimpleShape
	{
	private:
		//sf::RectangleShape rectangle;
		float height, length;
	public:
		//Rectangle(double leng, double heig, sf::Color);
		//void draw(sf::RenderWindow *);
	};

}

#endif // !_RECTANGLE_H_
