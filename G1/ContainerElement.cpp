#include "ContainerElement.h"

namespace G1 {
	namespace Layout {

		void ContainerElement::mainBeginPlay()
		{
			Parentable* parentable = getParent();
			while (parentable) {
				GameObject* gO = dynamic_cast<GameObject*>(parentable);
				if (gO) {
					Container* con = gO->getComponent<Container>();
					if (con) {
						mainContainer = con;
						break;
					}
					else {
						mainContainer = NULL;
					}
				}
				parentable = parentable->getParent();
			}
		}

		void ContainerElement::mainEventTick()
		{
			if (mainContainer) {
				Vector2 anchOff = mainContainer->anchorOffset(anchor);
				static_cast<Transformable*>(getParent())->setPosition(anchOff.x, anchOff.y);
			}
		}
	}
}
