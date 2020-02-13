#pragma once

#ifndef _IGAMEOBJECT_TICK_H_
#define _IGAMEOBJECT_TICK_H_

#include "ITick.h"
#include "IFixedTick.h"

namespace G1 {
	class IGameObjectTick : public ITick, public IFixedTick {
	protected:
		virtual void mainFixedEventTick() = 0;
		virtual void mainEventTickComponents() = 0;

	public:
		virtual void fixedEventTick() = 0;
	};
}

#endif // !_IGAMEOBJECT_TICK_H_
