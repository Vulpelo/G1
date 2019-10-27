#pragma once

#include "MainTick.h"

namespace G1 {

	class Tick : protected MainTick {

	protected:
		virtual void mainBeginPlay() = 0;
		virtual void mainEventTick() = 0;
		
	public:
		virtual void beginPlay() = 0;
		virtual void eventTick() = 0;
	};

}
