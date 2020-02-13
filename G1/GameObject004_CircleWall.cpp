#include "GameObject004_CircleWall.h"

void GameObject004_CircleWall::beginPlay()
{
	setSortingLayer(2);

	overlaps = false;

	color1 = sf::Color::Red;
	color2 = sf::Color::Green;

	rRend = new CircleRenderer(30, color1);
	addComponent(rRend);

	auto collidor = new CircleCollider(30, 0, 0);
	collidor->setOverlappable(false);
	collidor->setPhysicMaterial(PhysicMaterial(0.f, 1.0f));
	addComponent(collidor);

	rb = new Rigidbody();
	rb->setMass(1);
	rb->setGravity(Vector2(0, 0.00001f));
	addComponent(rb);
}

void GameObject004_CircleWall::eventTick()
{
	if (ControlInput::getInstantiate().keyDown(sf::Keyboard::O)) {
		rb->setVelocity(vel);
	}
	if (overlaps) {
		rRend->setColor(color2);
		overlaps = false;
	}
	else {
		rRend->setColor(color1);
	}
}

void GameObject004_CircleWall::isOverlaping(GameObject * overlaped)
{
	overlaps = true;
}
