#pragma once

#include "GameMap.h"
#include "Background.h"
#include "MapTileLadder.h"
#include "GameMaster.h"

#include "MapLoader.h"

#include "UIMainMenu.h"
#include "UIStartButton.h"

#include "GameObject001.h"
#include "Background.h"

using namespace G1;

class MapMainMenu :
	public GameMap
{
public:
	MapMainMenu() {
		Assets::getInstance().textures().load("./assets/environment/layers/back.png");
	};
	void startPlay() {
		Camera* cam = new Camera();
		cam->setMatchSize(true);
		cam->setActive(true);

		Background* bg = new Background(Assets::getInstance().textures().get("./assets/environment/layers/back.png"), Vector2(384, 500));
		bg->setScale(3, 2);
		bg->setPosition(0, 500);
		addGameObject(bg);

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

