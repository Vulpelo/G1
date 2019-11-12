#include "MapTileLadder.h"


MapTileLadder::MapTileLadder(int x, int y, const Layer& layer, unsigned int xSpan, unsigned int ySpan) :
	MapTile1(Sprite(Assets::getInstance().textures().get("ladder"), Vector2(16, 16)), x, y, false, layer, xSpan, ySpan)
{
}

void MapTileLadder::beginPlayCon()
{
	const Vector2& tileSize = MapTileProperties::getTileSize();
	RectangleCollider* rc = new RectangleCollider(
		tileSize.x * xSpan / 5,
		tileSize.y * ySpan,
		tileSize.x * xSpan / 2 - tileSize.x / 2,
		tileSize.y * ySpan / 2 - tileSize.y / 2);
	rc->setOverlappable(true);
	addComponent(rc);
}
