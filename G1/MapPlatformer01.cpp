#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01()
{
	Assets &assets = Assets::getInstance();
	assets.textures().load("./assets/spritesheets/player-idle.png");
	assets.textures().load("./assets/spritesheets/player-run.png");
	assets.textures().load("./assets/spritesheets/player-jump.png");
	assets.textures().load("./assets/environment/layers/back.png");
	assets.textures().load("./assets/spritesheets/player-crouch.png");
	
	assets.soundBuffers().load("grass_footsteps", "./assets/sounds/footsteps_grass.wav");
	assets.soundBuffers().load("music_1", "./assets/sounds/platformer_level03_loop.ogg");

	Audio::play("music_1", true);
	
	{ // Background
		Background* b = new Background(
			assets.textures().get("./assets/environment/layers/back.png"),
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

