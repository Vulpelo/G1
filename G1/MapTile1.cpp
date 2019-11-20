#include "MapTile1.h"

void MapTile1::updateScale()
{
	/* Setting scale so image is scaled depending from tile size*/
	Vector2 scale(2, 2);
	scale.x = MapTileProperties::getTileSize().x / initialImageSize.x;
	scale.y = MapTileProperties::getTileSize().y / initialImageSize.y;

	this->sprite.setScale(scale);
}

MapTile1::MapTile1(const G1::Sprite& sprite, int x, int y, bool collision, const Layer& layer, unsigned int xSpan, unsigned int ySpan) :
	MapTile(x, y, collision, layer, xSpan, ySpan)
{
	this->sprite = sprite;
	initialImageSize = sprite.getImageSize();
	updateScale();
	set(x, y, xSpan, ySpan);
}

void MapTile1::set(int x, int y, unsigned int xSpan, unsigned int ySpan)
{
	this->x = x;
	this->y = y;
	this->xSpan = xSpan;
	this->ySpan = ySpan;

	this->sprite.setImageSize(Vector2(initialImageSize.x * xSpan, initialImageSize.y * ySpan));

	setPosition(Vector2(x * MapTileProperties::getTileSize().x + MapTileProperties::getTileSize().x / 2, 
						y * MapTileProperties::getTileSize().y + MapTileProperties::getTileSize().y / 2));
}

void MapTile1::beginPlay() {
	if (collision) {
		const Vector2& tileSize = MapTileProperties::getTileSize();
		RectangleCollider* rc = new RectangleCollider(
			tileSize.x * xSpan, 
			tileSize.y * ySpan, 
			tileSize.x * xSpan / 2 - tileSize.x / 2,
			tileSize.y * ySpan / 2 - tileSize.y / 2);
		rc->setOverlappable(false);
		addComponent(rc);
	}
	addComponentCopy(this->sprite);

	beginPlayCon();
}

