#pragma once

#include "IMainTick.h"

namespace G1 {

	class ITick : protected IMainTick {

	protected:
		virtual void mainBeginPlay() = 0;
		virtual void mainEventTick() = 0;
		
	public:
		virtual void beginPlay() = 0;
		virtual void eventTick() = 0;
	};

}
