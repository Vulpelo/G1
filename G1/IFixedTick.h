#pragma once

#ifndef _IFIXED_TICK_H_
#define _IFIXED_TICK_H_

namespace G1 {
	class IFixedTick {
	protected:
		virtual void mainFixedEventTick() = 0;

	public:
		virtual void fixedEventTick() = 0;
	};
}

#endif // !_IFIXED_TICK_H_
