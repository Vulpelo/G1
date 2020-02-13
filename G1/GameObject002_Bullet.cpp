#include "GameObject002_Bullet.h"


GameObject002_Bullet::GameObject002_Bullet(float bounciness)
{
	CircleRenderer* cRend = new CircleRenderer(15, sf::Color::Red);
	addComponent(cRend);

	CircleCollider* cCollider = new CircleCollider(15, 0, 0);
	cCollider->setOverlappable(false);
	cCollider->setPhysicMaterial(PhysicMaterial(0.f, bounciness));
	addComponent(cCollider);

	rb = new Rigidbody();
	rb->setGravity(Vector2(0, 0));
	addComponent(rb);
}

void GameObject002_Bullet::beginPlay() {

	//destroy(10.0f);
}

void GameObject002_Bullet::eventTick()
{
	if (ControlInput::getInstantiate().keyDown(sf::Keyboard::Key::P)) {
		rb->setGravity(Vector2(0,30));
	}
}

void GameObject002_Bullet::isColliding(GameObject *)
{
	//std::cout << this << ":Bullet is Colliding\n";
}
