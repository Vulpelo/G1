#include "Properties.h"

int Properties::height = 900;
int Properties::width = 1024;
int Properties::bitPerPixel = 32;

GameMap* Properties::aMap = nullptr;

void Properties::setWindowSpec(int nWidth, int nHeight, int nBitPerPixel)
{
	Properties::width = nWidth;
	Properties::height = nHeight;
	Properties::bitPerPixel = nBitPerPixel;
}

void Properties::loadMap(GameMap* nMap)
{
	Properties::aMap = nMap;
}

GameMap * Properties::get_aMap()
{
	return Properties::aMap;
}

Properties::~Properties()
{
	if (Properties::aMap)
		delete Properties::aMap;
}
