#pragma once

#include <deque>

namespace G1 {
	typedef void(*fireFunction)();

	class EventHandler {
		friend class Engine;

		std::deque<fireFunction> functionsToFire;

		static EventHandler& getInstance() { static EventHandler instance; return instance; }

		void handle() {
			for each (fireFunction fun in functionsToFire)
			{
				fun();
			}
			functionsToFire.clear();
		}

	public:
		static void fireEvent(fireFunction fun) {
			EventHandler::getInstance().functionsToFire.push_back(fun);
		}
	};

}
