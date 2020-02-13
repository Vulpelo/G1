#include "MyUI.h"

void MyUI::startPlay()
{
	Camera* cam = Camera::getActiveCameras().at(0);
	Layout::Container* container = new Layout::Container(cam);
	addComponent(container);
}

void MyUI::beginPlay()
{
}

