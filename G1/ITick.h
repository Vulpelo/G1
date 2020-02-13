#pragma once

#include "IMainTick.h"

namespace G1 {

	class ITick : protected IMainTick {

	public:
		// played for all GameObject before beginPlay().
		virtual void startPlay() = 0;
		// played for all GameObject after startPlay()
		virtual void beginPlay() = 0;
		virtual void eventTick() = 0;
	};

}
