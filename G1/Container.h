#pragma once

#ifndef _CONTAINER_H_
#define _CONTAINER_H_


#include "Parentable.h"
#include "Component.h"
#include "RenderManager.h"

namespace G1::Layout {

	/// Manipulates position and scale of gameObject
	class Container : public Component, public Parentable {
		void mainEventTick();
	public:

		
	};

}

#endif //!_CONTAINER_H_
