#include "Ground01.h"

void Ground01::beginPlay()
{
	setLayer(Layer::GROUND);

	rRend = new RectangleRenderer(xLen, yLen, color1);
	addComponent(rRend);

	auto collider = new RectangleCollider(xLen, yLen, 0, 0, 0);
	collider->setOverlappable(false);
	addComponent(collider);
}
