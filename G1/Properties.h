#pragma once

#include "GameMap.h"

class Properties
{
	static GameMap* aMap;

public:
	// window spec
	static int width;
	static int height;
	static int bitPerPixel;

	static void setWindowSpec(int, int, int);
	static void loadMap(GameMap*);
	static GameMap* get_aMap();
	~Properties();
};

