#pragma once

#include "RectangleRenderer.h"
#include "ContainerElement.h"
#include "GameObject.h"
#include "Text.h"
#include "GameMaster.h"

using namespace G1;
using namespace G1::Layout;

class SquareUI : public GameObject {
	sf::Font font;
	Anchor anchor = Anchor::MIDDLE;

public:
	SquareUI() {}
	SquareUI(Anchor anchor) { this->anchor = anchor; }
	void beginPlay();
};
