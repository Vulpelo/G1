#include "Parentable.h"

namespace G1 {

Parentable & Parentable::getTopParent()
{
	Parentable *next = this;
	while (next->getParent() != NULL) {
		next = next->getParent();
	}
	return *next;
}

}
