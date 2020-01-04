#pragma once

#include "GameMap.h"
#include "Background.h"
#include "MapTileLadder.h"
#include "GameMaster.h"

#include "MapLoader.h"

#include "UIMainMenu.h"
#include "UIStartButton.h"

#include "GameObject001.h"

using namespace G1;

class MapMainMenu :
	public GameMap
{
public:
	MapMainMenu() {};
	void startPlay() {
		Camera* cam = new Camera();
		cam->setMatchSize(true);
		cam->setActive(true);

		UIMainMenu* uiB = new UIMainMenu();
		addGameObject(uiB);

		UIStartButton* sB = new UIStartButton();
		sB->setParent(uiB);
		addGameObject(sB);

		//GameObject001* gg = new GameObject001();
		//gg->setPosition(0, 0);
		//addGameObject(gg);
	};
};

