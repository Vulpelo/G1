#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01()
{
	Assets &assets = Assets::getInstance();
	assets.textures().load("./assets/spritesheets/player-idle.png");
	assets.textures().load("./assets/spritesheets/player-run.png");
	assets.textures().load("./assets/spritesheets/player-jump.png");
	assets.textures().load("./assets/spritesheets/player-crouch.png"); 

	assets.textures().load("./assets/environment/layers/back.png");
	assets.textures().load("grass_ul", "./assets/environment/tiles/grass_ul.png");
	assets.textures().get("grass_ul").setRepeated(true);
	assets.textures().load("grass_um", "./assets/environment/tiles/grass_um.png");
	assets.textures().get("grass_um").setRepeated(true);
	assets.textures().load("grass_ur", "./assets/environment/tiles/grass_ur.png");
	assets.textures().get("grass_ur").setRepeated(true);
	assets.textures().load("grass_ml", "./assets/environment/tiles/grass_ml.png");
	assets.textures().get("grass_ml").setRepeated(true);
	assets.textures().load("grass_mm", "./assets/environment/tiles/grass_mm.png");
	assets.textures().get("grass_mm").setRepeated(true);
	assets.textures().load("grass_mr", "./assets/environment/tiles/grass_mr.png");
	assets.textures().get("grass_mr").setRepeated(true);
	assets.textures().load("grass_dl", "./assets/environment/tiles/grass_dl.png");
	assets.textures().get("grass_dl").setRepeated(true);
	assets.textures().load("grass_dm", "./assets/environment/tiles/grass_dm.png");
	assets.textures().get("grass_dm").setRepeated(true);
	assets.textures().load("grass_dr", "./assets/environment/tiles/grass_dr.png");
	assets.textures().get("grass_dr").setRepeated(true);
	
	assets.soundBuffers().load("grass_footsteps", "./assets/sounds/footsteps_grass.wav");
	assets.soundBuffers().load("music_1", "./assets/sounds/platformer_level03_loop.ogg");

	Audio::play("music_1", true);
	

	MapTileProperties::setTileSize(Vector2(50, 50));

	{ // Background
		Background* b = new Background(
			assets.textures().get("./assets/environment/layers/back.png"),
			Vector2(384, 240));

		b->setTransform(Transform(Vector2(300, 0), Vector2(3, 3)));
		objects.push_back(b);
	}
	{ // Map tiles
		// Ground
		MapTileProperties::setTileSize(Vector2(30, 30));

		MapTile1 tile(Sprite(assets.textures().get("grass_um"), Vector2(16, 16)), 0, 0, true, Layer::GROUND, 6, 1);
		addGameObject(tile);
		tile.set(0,0,6,1); addGameObject(tile);
		tile.set(6, -1, 2, 1); addGameObject(tile);
		tile.set(8, 0, 6, 1); addGameObject(tile);
		tile.set(9, -3, 4, 1); addGameObject(tile);
		tile.set(14, -1, 3, 1); addGameObject(tile);
		tile.set(17, -2, 2, 1); addGameObject(tile);
		tile.set(19, -1, 3, 1); addGameObject(tile);
		tile.set(24, -1, 4, 1); addGameObject(tile);

		Sprite spriteTiles[9] = {
			Sprite(assets.textures().get("grass_ul"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_um"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_ur"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_ml"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_mm"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_mr"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_dl"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_dm"), Vector2(16, 16)), 
			Sprite(assets.textures().get("grass_dr"), Vector2(16, 16)) };
		MapTile9 tile9(spriteTiles, -4, 2, true, Layer::GROUND, 5, 5);
		addGameObject(tile9);
	}

	{// player
		PlatformerPlayer* o = new PlatformerPlayer();
		o->setTransform(Transform(20, -40, 0));

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

