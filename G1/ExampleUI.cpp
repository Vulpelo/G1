#include "ExampleUI.h"

void ExampleUI::startPlay()
{
	Camera* cam = Camera::getActiveCameras().at(0);
	Layout::Container* container = new Layout::Container(cam);
	addComponent(container);
}

void ExampleUI::beginPlay()
{
}
