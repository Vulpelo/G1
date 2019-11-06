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

void MapTile9::set(int x, int y, unsigned int xSpan, unsigned int ySpan)
{
	this->x = x;
	this->y = y;
	this->xSpan = xSpan;
	this->ySpan = ySpan;

	const Vector2& tileSize = MapTileProperties::getTileSize();

	float nXPos = x * MapTileProperties::getTileSize().x + MapTileProperties::getTileSize().x / 2;
	float nYPos = y * MapTileProperties::getTileSize().y + MapTileProperties::getTileSize().y / 2;

	if (xSpan > 0 && ySpan > 0) {
		this->spriteTiles[(int)SpriteTilePos::UL].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::UL].initialImageSize.x,
					this->spriteTiles[(int)SpriteTilePos::UL].initialImageSize.y));

		this->spriteTiles[(int)SpriteTilePos::UM].sprite.move(tileSize.x, 0);
		this->spriteTiles[(int)SpriteTilePos::UM].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::UM].initialImageSize.x * (xSpan - 2),
					this->spriteTiles[(int)SpriteTilePos::UM].initialImageSize.y));

		this->spriteTiles[(int)SpriteTilePos::UR].sprite.move(tileSize.x * (xSpan - 1), 0);
		this->spriteTiles[(int)SpriteTilePos::UR].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::UR].initialImageSize.x,
					this->spriteTiles[(int)SpriteTilePos::UR].initialImageSize.y));


		this->spriteTiles[(int)SpriteTilePos::ML].sprite.move(0, tileSize.y);
		this->spriteTiles[(int)SpriteTilePos::ML].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::ML].initialImageSize.x,
					this->spriteTiles[(int)SpriteTilePos::ML].initialImageSize.y * (ySpan - 2)));

		this->spriteTiles[(int)SpriteTilePos::MM].sprite.move(
			tileSize.x,
			tileSize.y);
		this->spriteTiles[(int)SpriteTilePos::MM].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::MM].initialImageSize.x * (xSpan - 2),
					this->spriteTiles[(int)SpriteTilePos::MM].initialImageSize.y * (ySpan - 2)));

		this->spriteTiles[(int)SpriteTilePos::MR].sprite.move(
			tileSize.x * (xSpan - 1),
			tileSize.y);
		this->spriteTiles[(int)SpriteTilePos::MR].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::MR].initialImageSize.x,
					this->spriteTiles[(int)SpriteTilePos::MR].initialImageSize.y * (ySpan - 2)));


		this->spriteTiles[(int)SpriteTilePos::DL].sprite.move(0, tileSize.y * (ySpan - 1));
		this->spriteTiles[(int)SpriteTilePos::DL].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::DL].initialImageSize.x,
				this->spriteTiles[(int)SpriteTilePos::DL].initialImageSize.y));

		this->spriteTiles[(int)SpriteTilePos::DM].sprite.move(
			tileSize.x,
			tileSize.y * (ySpan - 1));
		this->spriteTiles[(int)SpriteTilePos::DM].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::DM].initialImageSize.x * (xSpan - 2),
				this->spriteTiles[(int)SpriteTilePos::DM].initialImageSize.y));

		this->spriteTiles[(int)SpriteTilePos::DR].sprite.move(
			tileSize.x * (xSpan - 1),
			tileSize.y * (ySpan - 1));
		this->spriteTiles[(int)SpriteTilePos::DR].sprite.setImageSize(
			Vector2(this->spriteTiles[(int)SpriteTilePos::DR].initialImageSize.x,
				this->spriteTiles[(int)SpriteTilePos::DR].initialImageSize.y));
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

	for (size_t i = 0; i < 9; i++) {
		addComponent(&this->spriteTiles[i].sprite);
	}
}
