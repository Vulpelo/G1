#include "Time.h"

namespace G1 {

	float Time::deltaTime = 0;

	Time::Time()
	{
		deltaTime = 0;
	}
	void Time::restart()
	{
		this->deltaTime = dClock.restart().asSeconds();
	}

	float Time::getDeltaTime()
	{
		return deltaTime;
	}

}
