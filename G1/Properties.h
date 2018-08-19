#pragma once

#ifndef PROPERTIES_H
#define PROPERTIES_H

//#include "GameMap.h"

class Properties
{

public:
	// window spec
	static int width;
	static int height;
	static int bitPerPixel;

	static void setWindowSpec(int, int, int);
	//static void loadMap(GameMap*);
	//static GameMap* get_aMap();
	~Properties();
};

#endif // !PROPERTIES_H
