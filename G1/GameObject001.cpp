#include "GameObject001.h"


void GameObject001::beginPlay() {
	CircleRenderer* cRend = new CircleRenderer(30, sf::Color::Green);

	components.push_back(cRend);
}

