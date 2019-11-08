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
		MapTileProperties::setTileSize(Vector2(30, 30));

		// Overall ground
		MapTile9 tile9(spriteTiles, 0, 0, true, Layer::GROUND, 22, 10);
		addGameObject(tile9);
		tile9.set(24, 0, 16, 11, (int)MapTile9::SpriteTilePos::MR); addGameObject(tile9);
		tile9.set(24, -1, 7, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
		tile9.set(38,-1, 2, 2, (int)MapTile9::SpriteTilePos::DM | (int)MapTile9::SpriteTilePos::MR); addGameObject(tile9);

		// left / right wall
		tile9.set(-30, -21, 30, 30); addGameObject(tile9);
		tile9.set(40, -20, 30, 30); addGameObject(tile9);

		// Ground / bomps
		tile9.set(5, -1, 3, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
		tile9.set(14, -1, 8, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
		tile9.set(16, -2, 3, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);

		// upper ground
		tile9.set(28, -19, 10, 1, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
		tile9.set(27, -20, 5, 2, (int)MapTile9::SpriteTilePos::MR); addGameObject(tile9);
		tile9.set(-1, -21, 4, 2, (int)MapTile9::SpriteTilePos::ML); addGameObject(tile9);


		// cave begining upper ground
		tile9.set(30, -6, 5, 2, (int)MapTile9::SpriteTilePos::ML); addGameObject(tile9);
		tile9.set(28, -12, 3, 8, (int)MapTile9::SpriteTilePos::ML); addGameObject(tile9);

		tile9.set(23, -16, 4, 2, (int)MapTile9::SpriteTilePos::MR | (int)MapTile9::SpriteTilePos::UR); addGameObject(tile9);
		tile9.set(26, -16, 3, 12, (int)MapTile9::SpriteTilePos::ML); addGameObject(tile9);
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

