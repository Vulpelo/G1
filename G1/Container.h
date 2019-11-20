#pragma once

#ifndef _CONTAINER_H_
#define _CONTAINER_H_


#include "Parentable.h"
#include "Component.h"
#include "RenderManager.h"
#include "Camera.h"

namespace G1 {
	namespace Layout {

		enum class Anchor {
			UP_LEFT, UP, UP_RIGHT,
			MIDDLE_LEFT, MIDDLE, MIDDLE_RIGHT,
			DOWN_LEFT, DOWN, DOWM_RIGHT
		};

		/// Manipulates position and scale of gameObject
		class Container : public Component, public Parentable {
			// camera view to which Container will be matched
			Camera* camera = NULL;

			void mainEventTick();
		public:

			/// Pass pointer to camera to which container will be matching (scalling, position)
			Container(Camera* camera) { this->camera = camera; };

			Vector2 anchorOffset(Anchor anchor);

		};

	}
}

#endif //!_CONTAINER_H_
