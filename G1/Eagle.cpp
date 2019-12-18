#include "Eagle.h"

void Eagle::startPlay()
{
	Sprite* sprite = new Sprite(Assets::getInstance().textures().get("eagle"), Vector2(41,41));
	addComponent(sprite);

	EagleAnimator* animator = new EagleAnimator(*sprite);
	addComponent(animator);

	rb = new Rigidbody();
	rb->setGravity(Vector2(0, 0));
	addComponent(rb);
}

void Eagle::eventTick()
{
	auto cols = Physics::circleOverlaps(getWorldPosition(), seeRadious, static_cast<int>(Layer::PLAYER));
	if (cols.empty()) {
		target = NULL;
	}
	else {
		target = cols.at(0)->getParent();
	}
}

void Eagle::fixedEventTick()
{
	if (target) {
		Vector2 direction = target->getWorldPosition() - getWorldPosition();
		float angle = direction.angle();
		rb->setVelocity(Vector2::byAngleAndLength(angle, speed));
		if (direction.x > 0) {
			setScale(-1, 1);
		}
		else {
			setScale(1, 1);
		}
	} else {
		rb->setVelocity(Vector2(0, 0));
	}
}
