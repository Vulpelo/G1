#pragma once

#ifndef _TIME_H_
#define _TIME_H_

#include <SFML\Graphics.hpp>

namespace G1 {

	class Time {
		sf::Clock dClock;
		sf::Time dTime;

		static float deltaTime;
	public:
		Time();
		void restart();
		static float getDeltaTime();
	};

}

#endif // !_TIME_H_
