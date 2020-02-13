#pragma once

#include <stdlib.h>

namespace G1 {
	class Parentable {
	protected:
		Parentable * parent = NULL;
	
	public:
		virtual Parentable & getTopParent();
		virtual Parentable* getParent() { return parent; };
		void setParent(Parentable* parent) { this->parent = parent; };
	};

}


