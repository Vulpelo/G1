#include "MapPlatformer01.h"

MapPlatformer01::MapPlatformer01() {
	MapTileProperties::setTileSize(Vector2(30, 30));

	MapLoader loader;
	loader.load(this, "./assets/maps_xml/mapPlatformer01.xml");
	
	Assets &assets = Assets::getInstance();
	Audio::play("music_1", true);

	//{
	//	Gem* gem = new Gem();
	//	gem->setTransform(Transform(50, -30, 0));
	//	addGameObject(gem);
	//}

	Eagle* eagle = new Eagle(findGameObjectByTag("Player"));
	eagle->setTransform(Transform(1000, -350, 0));
	addGameObject(eagle);


	//{ // ground
	//	Ground01* o = new Ground01(1000, 50);
	//	o->setTransform(Transform(500, 800, 0));

	//	objects.push_back(o);
	//}
	//{// floating block
	//	Ground01* o = new Ground01(50, 50);
	//	o->setTransform(Transform(500, 700, 0));

	//	objects.push_back(o);
	//}
	//{
	//	Ground01* o = new Ground01(50, 50);
	//	o->setTransform(Transform(700, 750, 0));

	//	objects.push_back(o);
	//}
	//{
	//	Ground01* o = new Ground01(50, 600);
	//	o->setTransform(Transform(900, 300, 0));

	//	objects.push_back(o);
	//}

	//{
	//	GameObject004_CircleWall* w = new GameObject004_CircleWall();
	//	w->setTransform(Transform(310, -50, 0));

	//	objects.push_back(w);
	//}
	//
	{
		MyUI* ui = new MyUI();
		objects.push_back(ui);

		UiImage* uiImage = new UiImage();
		uiImage->setParent(ui);
		objects.push_back(uiImage);
	}
	
}

