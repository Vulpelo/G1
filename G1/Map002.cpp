#include "Map002.h"

Map002::Map002()
{
	Camera* cam = new Camera();
	cam->setMatchSize(true);
	cam->setActive(true);

	{
		ExampleUI* ui = new ExampleUI();
		objects.push_back(ui);
		{
			SquareUI* uiImage = new SquareUI(Anchor::UP_LEFT);
			uiImage->setParent(ui);
			objects.push_back(uiImage);
		}
		{
			SquareUI* uiImage = new SquareUI(Anchor::DOWM_RIGHT);
			uiImage->setParent(ui);
			objects.push_back(uiImage);
		}
		{
			SquareUI* uiImage = new SquareUI(Anchor::UP_RIGHT);
			uiImage->setParent(ui);
			objects.push_back(uiImage);
		}
		{
			SquareUI* uiImage = new SquareUI(Anchor::MIDDLE);
			uiImage->setParent(ui);
			objects.push_back(uiImage);
		}
		{
			SquareUI* uiImage = new SquareUI(Anchor::DOWN_LEFT);
			uiImage->setParent(ui);
			objects.push_back(uiImage);
		}
	}
}

void Map002::eventTick()
{
}
