#include "GameObject002_Bullet.h"


GameObject002_Bullet::GameObject002_Bullet()
{
	CircleRenderer* cRend = new CircleRenderer(15, sf::Color::Red);
	addComponent(cRend);

	Rigidbody* rb = new Rigidbody();
	addComponent(rb);
}

void GameObject002_Bullet::beginPlay() {

	destroy(5.0f);
}
