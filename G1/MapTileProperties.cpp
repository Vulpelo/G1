#include "MapTileProperties.h"

Vector2 MapTileProperties::tileSize(32,32);

const Vector2 & MapTileProperties::getTileSize()
{
	return tileSize;
	// TODO: insert return statement here
}

void MapTileProperties::setTileSize(Vector2 & ntileSize)
{
	MapTileProperties::tileSize = ntileSize;
}
