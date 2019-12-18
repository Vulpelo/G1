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

	startPosition = getWorldPosition();
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
	Vector2 direction;
	if (target) {
		direction = target->getWorldPosition() - getWorldPosition();
	}
	else {
		direction = startPosition - getWorldPosition();
	}
	
	if (direction.lengthNoSqrt() > distancePrecision * distancePrecision) {
		float angle = direction.angle();
		rb->setVelocity(Vector2::byAngleAndLength(angle, speed));
		if (direction.x > 0) {
			setScale(-1, 1);
		}
		else {
			setScale(1, 1);
		}
	} 
	else {
		rb->setVelocity(Vector2(0, 0));
	}
}
