#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01()
{
	Assets &assets = Assets::getInstance();
	assets.loadTexture("./assets/spritesheets/player-idle.png");
	assets.loadTexture("./assets/spritesheets/player-run.png");
	assets.loadTexture("./assets/spritesheets/player-jump.png");
	assets.loadTexture("./assets/environment/layers/back.png");
	
	{ // Background
		Background* b = new Background(
			assets.getTexture("./assets/environment/layers/back.png"),
			Vector2(384, 240));

		b->setTransform(Transform(Vector2(400, 800), Vector2(3, 3) ));

		objects.push_back(b);
	}

	{
		PlatformerPlayer* o = new PlatformerPlayer();
		o->setTransform(Transform(200, 725, 0));

		objects.push_back(o);
	}
	{ // ground
		Ground01* o = new Ground01(1000, 50);
		o->setTransform(Transform(500, 800, 0));

		objects.push_back(o);
	}
	{// floating block
		Ground01* o = new Ground01(50, 50);
		o->setTransform(Transform(500, 700, 0));

		objects.push_back(o);
	}
	{
		Ground01* o = new Ground01(50, 50);
		o->setTransform(Transform(700, 750, 0));

		objects.push_back(o);
	}

	{
		Ground01* o = new Ground01(50, 600);
		o->setTransform(Transform(900, 300, 0));

		objects.push_back(o);
	}
}

