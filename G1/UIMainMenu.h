#pragma once

#include "GameObject.h"
#include "Container.h"

using namespace G1;

class UIMainMenu : public GameObject {
public:
	void startPlay() {
		Layout::Container* con = new Layout::Container(Camera::getActiveCameras()[0]);
		addComponent(con);
	};
};
