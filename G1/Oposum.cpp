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

	RectangleCollider* collider = new RectangleCollider(15, 15, 0, 0);
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
void Oposum::startOverlapping(GameObject * otherGameObject)
{
	if (!dead) {
		if (otherGameObject->isLayer(Layer::PLAYER)) {
			Vector2 direction = this->getWorldPosition() - otherGameObject->getWorldPosition();
			float angle = direction.angle();

			if (angle < 45 || angle > 315) {
				dead = true;
				animator->setBool("dead", dead);
				rb->setVelocity(Vector2());
				destroy(1.f);
				(dynamic_cast<IPlayerEnemyInteraction*>(otherGameObject))->bounce();

			}
			else {
				(dynamic_cast<IPlayerEnemyInteraction*>(otherGameObject))->takeDamage(damage);
			}
		}
	}
}
