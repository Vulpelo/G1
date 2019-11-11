#include "GameObject002_Bullet.h"


GameObject002_Bullet::GameObject002_Bullet()
{
	CircleRenderer* cRend = new CircleRenderer(15, sf::Color::Red);
	addComponent(cRend);

	CircleCollider* cCollider = new CircleCollider(15, 0, 0);
	cCollider->setOverlappable(false);
	cCollider->setPhysicMaterial(PhysicMaterial(0.f, 1.f));
	addComponent(cCollider);

	Rigidbody* rb = new Rigidbody();
	addComponent(rb);
}

void GameObject002_Bullet::beginPlay() {

	//destroy(10.0f);
}

void GameObject002_Bullet::isColliding(GameObject *)
{
	//std::cout << this << ":Bullet is Colliding\n";
}
