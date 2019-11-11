#include "Ladder.h"

void Ladder::beginPlay()
{
	setLayer(Layer::CLIMBABLE);

	const Vector2& tileSize = MapTileProperties::getTileSize();
	RectangleCollider* rC = new RectangleCollider(tileSize.x, tileSize.y * yLength);
	addComponent(rC);

	Sprite* sprite = new Sprite(Assets::getInstance().textures().get("ladder"), Vector2(16, 16 * yLength));
	addComponent(sprite);
}
