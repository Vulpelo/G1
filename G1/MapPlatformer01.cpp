#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01() {
	MapLoader loader;
	loader.load(this, "./assets/maps_xml/mapPlatformer01.xml");
	
	Assets &assets = Assets::getInstance();
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
		MapTileProperties::setTileSize(Vector2(30, 30));

		// ground floating sprites
		Sprite spriteGroundFloatTiles[9] = {
			Sprite(assets.textures().get("grass_float_b"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_m"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_e"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_b"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_m"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_e"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_b"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_m"), Vector2(16, 16)),
			Sprite(assets.textures().get("grass_float_e"), Vector2(16, 16))
		};
		int floatGroundIgnore = (int)MapTile9::SpriteTilePos::DR | (int)MapTile9::SpriteTilePos::DM | (int)MapTile9::SpriteTilePos::DL | (int)MapTile9::SpriteTilePos::ML | (int)MapTile9::SpriteTilePos::MR | (int)MapTile9::SpriteTilePos::MM;
		MapTile9 tile9floatGround(spriteGroundFloatTiles, 22, -6, true, Layer::GROUND, 2, 1, floatGroundIgnore); addGameObject(tile9floatGround);
		tile9floatGround.set(20, -7, 2, 1, floatGroundIgnore); addGameObject(tile9floatGround);
		tile9floatGround.set(14, -8, 6, 1, floatGroundIgnore); addGameObject(tile9floatGround);
		tile9floatGround.set(11, -9, 3, 1, floatGroundIgnore); addGameObject(tile9floatGround);

		// bridge
		MapTile1 tile1Bridge(Sprite(assets.textures().get("bridge"), Vector2(16, 16)), 27, -6, true, Layer::GROUND, 5, 1); addGameObject(tile1Bridge);


		// ground sprites
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
		// Overall ground

		MapTile9 tile9(spriteTiles, -10, 0, true, Layer::GROUND, 37, 20); addGameObject<MapTile9>(tile9);
			tile9.set(5, -1, 13, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
			tile9.set(6, -2, 1, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
					tile9.set(13, -2, 5, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
						tile9.set(14, -3, 4, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
			tile9.set(25, -6, 2, 7, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
		
		// second part after bradge
		tile9.set(32, -5, 26, 26); addGameObject(tile9);
			tile9.set(32, -6, 12, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
			// TODO: ladder here
				tile9.set(35, -7, 9, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
					tile9.set(37, -8, 3, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
				// TODO: spikes here
					tile9.set(41, -8, 3, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);
			tile9.set(49, -6, 20, 2, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);

		tile9.set(53, -18, 20, 10); addGameObject(tile9);

		// left wall
		tile9.set(-10, -20, 10, 21, (int)MapTile9::SpriteTilePos::DM); addGameObject(tile9);

		//ladders
		MapTileLadder tileLadder(24, -6, Layer::CLIMBABLE, 1, 6); addGameObject(tileLadder);
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

	{
		GameObject004_CircleWall* w = new GameObject004_CircleWall();
		w->setTransform(Transform(310, -50, 0));

		objects.push_back(w);
	}

	{
		MyUI* ui = new MyUI();
		objects.push_back(ui);

		UiImage* uiImage = new UiImage();
		uiImage->setParent(ui);
		objects.push_back(uiImage);
	}
}

