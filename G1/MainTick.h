#pragma once

namespace G1 {

	class MainTick {

	protected:
		virtual void mainBeginPlay() = 0;
		virtual void mainEventTick() = 0;
	};

}
