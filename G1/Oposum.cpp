#include "Oposum.h"

void Oposum::startPlay()
{
	Sprite* sprite = new Sprite();
	addComponent(sprite);

	animator = new OposumAnimator(*sprite);
	addComponent(animator);

	rb = new Rigidbody();
	rb->setGravity(Vector2());
	addComponent(rb);

	RectangleCollider* collider = new RectangleCollider(3, 3, 0, -10);
	collider->setOverlappable(true);
	addComponent(collider);
}

void Oposum::eventTick()
{
}

void Oposum::fixedEventTick()
{
	if (!dead) {
		if (!Physics::circleOverlaps(getWorldPosition() + Vector2(checkDistance * dir, 0), 3.f, static_cast<int>(Layer::GROUND)).empty() ||
			Physics::circleOverlaps(getWorldPosition() + Vector2(checkDistance * dir, checkDistance), 3.f, static_cast<int>(Layer::GROUND)).empty())
		{
			dir *= -1;
			setScale(-dir, 1);
		}
		rb->setVelocity(Vector2(dir * speed, 0.0f));
	}
}
void Oposum::startOverlaping(GameObject * otherGameObject)
{
	if (otherGameObject->isLayer(Layer::PLAYER)) {
		dead = true;
		animator->setBool("dead", dead);
		rb->setVelocity(Vector2());
		destroy(1.f);
	}
}
