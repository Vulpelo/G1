#pragma once

#ifndef _CONTAINER_ELEMENT_H_
#define _CONTAINER_ELEMENT_H_

#include "Component.h"
#include "Container.h"

namespace G1 {
	namespace Layout {

		class ContainerElement : public Component, public Parentable {
			Anchor anchor = Anchor::MIDDLE;

			Container* mainContainer = NULL;
			void mainBeginPlay();
			void mainEventTick();

		public:
			void setAnchor(Anchor anchor) { this->anchor = anchor; }
		};
	}
}
#endif // !_CONTAINER_ELEMENT_H_

//TODO: destroy gameObject -> wraz z dzieæmi, bo dzieci nie mog¹ funkcjonowaæ bez rodzica
//TODO: getChild-> aby usun¹æ wszystkich potomków po wykonaniu polecenia destroy()