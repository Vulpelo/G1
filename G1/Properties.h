#pragma once

#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_

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

#endif // !_PROPERTIES_H_
