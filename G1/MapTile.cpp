#include "MapTile.h"

Vector2 MapTile::tileSize(32, 32);

MapTile::MapTile(const G1::Sprite & sprite, int x, int y, bool collision, const Layer& layer, unsigned int xSpan, unsigned int ySpan) :
	sprite(sprite), x(x), y(y), xSpan(xSpan), ySpan(ySpan), collision(collision)
{
	setLayer(layer);

	/* Setting scale so image is scaled depending from tile size*/
	Vector2 scale(2,2);
	const Vector2& size = this->sprite.getImageSize();
	scale.x = tileSize.x / size.x;
	scale.y = tileSize.y / size.y;

	this->sprite.setScale(scale);
	
	this->sprite.setImageSize(Vector2(size.x * xSpan, size.y * ySpan));
	
	setPosition(Vector2(x * tileSize.x + tileSize.x/2, y * tileSize.y + tileSize.y / 2));
}

void MapTile::beginPlay() {
	if (collision) {
		RectangleCollider* rc = new RectangleCollider(
			tileSize.x * xSpan, 
			tileSize.y * ySpan, 
			tileSize.x * xSpan / 2 - tileSize.x / 2,
			tileSize.y * ySpan / 2 - tileSize.y / 2);
		rc->setOverlappable(false);
		addComponent(rc);
	}
	addComponent(&this->sprite);
}

void MapTile::setTileSize(Vector2 & ntileSize)
{
	MapTile::tileSize = ntileSize;
}
