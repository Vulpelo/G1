#include "MapTile9.h"

void MapTile9::updateScale()
{
	Vector2 scale;
	for (size_t i = 0; i < 9; i++) {
		/* Setting scale so image is scaled depending from tile size*/
		scale.x = MapTileProperties::getTileSize().x / spriteTiles[i].initialImageSize.x;
		scale.y = MapTileProperties::getTileSize().y / spriteTiles[i].initialImageSize.y;

		this->spriteTiles[i].sprite.setScale(scale);
	}
}

MapTile9::MapTile9(G1::Sprite tiles[9], int x, int y, bool collision, const Layer & layer, unsigned int xSpan, unsigned int ySpan)
	: MapTile(x, y, collision, layer, xSpan, ySpan)
{
	for (size_t i = 0; i < 9; i++) {
		this->spriteTiles[i].sprite = std::move(tiles[i]);
		this->spriteTiles[i].initialImageSize = this->spriteTiles[i].sprite.getImageSize();
	}
	updateScale();
	set(x, y, xSpan, ySpan);
}

void MapTile9::set(int x, int y, unsigned int xSpan, unsigned int ySpan, int ignore)
{
	this->x = x;
	this->y = y;
	this->xSpan = xSpan;
	this->ySpan = ySpan;

	const Vector2& tileSize = MapTileProperties::getTileSize();

	float nXPos = x * MapTileProperties::getTileSize().x + MapTileProperties::getTileSize().x / 2;
	float nYPos = y * MapTileProperties::getTileSize().y + MapTileProperties::getTileSize().y / 2;

	if (xSpan > 0 && ySpan > 0) {
		if (! (ignore & (int)SpriteTilePos::UL) ) {
			this->spriteTiles[0].sprite.setImageSize(
				Vector2(this->spriteTiles[0].initialImageSize.x,
						this->spriteTiles[0].initialImageSize.y));
		}
		else {
			this->spriteTiles[0].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::UM)) {
			this->spriteTiles[1].sprite.setPosition(tileSize.x, 0);
			this->spriteTiles[1].sprite.setImageSize(
				Vector2(this->spriteTiles[1].initialImageSize.x * (xSpan - 2),
					this->spriteTiles[1].initialImageSize.y));
		}
		else {
			this->spriteTiles[1].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::UR)) {
			this->spriteTiles[2].sprite.setPosition(tileSize.x * (xSpan - 1), 0);
			this->spriteTiles[2].sprite.setImageSize(
				Vector2(this->spriteTiles[2].initialImageSize.x,
						this->spriteTiles[2].initialImageSize.y));
		}
		else {
			this->spriteTiles[2].sprite.setEnabled(false);
		}

		if (!(ignore & (int)SpriteTilePos::ML)) {
			this->spriteTiles[3].sprite.setPosition(0, tileSize.y);
			this->spriteTiles[3].sprite.setImageSize(
				Vector2(this->spriteTiles[3].initialImageSize.x,
					this->spriteTiles[3].initialImageSize.y * (ySpan - 2)));
		}
		else {
			this->spriteTiles[3].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::MM)) {
			this->spriteTiles[4].sprite.setPosition(0, 0);
			this->spriteTiles[4].sprite.setImageSize(
				Vector2(this->spriteTiles[4].initialImageSize.x * (xSpan),
					this->spriteTiles[4].initialImageSize.y * (ySpan)));
		}
		else {
			this->spriteTiles[4].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::MR)) {
			this->spriteTiles[5].sprite.setPosition( tileSize.x * (xSpan - 1), tileSize.y);
			this->spriteTiles[5].sprite.setImageSize(
				Vector2(this->spriteTiles[5].initialImageSize.x,
					this->spriteTiles[5].initialImageSize.y * (ySpan - 2)));
		}
		else {
			this->spriteTiles[5].sprite.setEnabled(false);
		}

		if (!(ignore & (int)SpriteTilePos::DL)) {
			this->spriteTiles[6].sprite.setPosition(0, tileSize.y * (ySpan - 1));
			this->spriteTiles[6].sprite.setImageSize(
				Vector2(this->spriteTiles[6].initialImageSize.x,
					this->spriteTiles[6].initialImageSize.y));
		}
		else {
			this->spriteTiles[6].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::DM)) {
			this->spriteTiles[7].sprite.setPosition(tileSize.x, tileSize.y * (ySpan - 1));
			this->spriteTiles[7].sprite.setImageSize(
				Vector2(this->spriteTiles[7].initialImageSize.x * (xSpan - 2),
					this->spriteTiles[7].initialImageSize.y));
		}
		else {
			this->spriteTiles[7].sprite.setEnabled(false);
		}
		if (!(ignore & (int)SpriteTilePos::DR)) {
			this->spriteTiles[8].sprite.setPosition( tileSize.x * (xSpan - 1), tileSize.y * (ySpan - 1));
			this->spriteTiles[8].sprite.setImageSize(
				Vector2(this->spriteTiles[8].initialImageSize.x,
					this->spriteTiles[8].initialImageSize.y));
		}
		else {
			this->spriteTiles[8].sprite.setEnabled(false);
		}
	}

	setPosition(Vector2(nXPos, nYPos));
}

void MapTile9::beginPlay()
{
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

	addComponent(&this->spriteTiles[4].sprite);
	for (size_t i = 0; i < 9; i++) {
		if (i == 4) continue;
		addComponent(&this->spriteTiles[i].sprite);
	}
}
