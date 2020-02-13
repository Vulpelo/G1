#pragma once

#include "RectangleRenderer.h"
#include "ContainerElement.h"
#include "GameObject.h"
#include "Text.h"
#include "GameMaster.h"

using namespace G1;
using namespace G1::Layout;

class UiImage : public GameObject {
	sf::Font font;

public:
	void beginPlay();
};
