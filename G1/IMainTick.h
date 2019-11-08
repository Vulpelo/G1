#pragma once

namespace G1 {

	class IMainTick {

	protected:
		virtual void mainBeginPlay() = 0;
		virtual void mainEventTick() = 0;
	};

}
