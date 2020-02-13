#include "Time.h"

namespace G1 {

	float Time::deltaTime = 0;
	sf::Clock Time::dClock;
	sf::Time Time::dTime;

	Time::Time()
	{
		deltaTime = 0;
	}
	void Time::restart()
	{
		deltaTime = dClock.restart().asSeconds();
	}

	float Time::getDeltaTime()
	{
		return deltaTime;
	}

}
