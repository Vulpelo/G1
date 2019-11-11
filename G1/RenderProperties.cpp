#include "RenderProperties.h"

namespace G1 {

	sf::RenderWindow* RenderProperties::window = nullptr;

	RenderProperties::~RenderProperties()
	{
		if (window) {
			delete window;
		}
	}

}
