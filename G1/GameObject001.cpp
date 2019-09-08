#include "GameObject001.h"


void GameObject001::beginPlay() {
	c = *ControlInput::getInstantiate();

	speed = 500.0f;
	rotationSpeed = 50.0f;
	shootingSpeed = 1.0f;
	a_shootingSpeed = 0.2f;

	aColor = false;
	changeColor = false;

	color1 = sf::Color::Yellow;
	color2 = sf::Color::Blue;

	rend = new RectangleRenderer(60, 60, color1);
	addComponent(rend);

	auto collidor = new RectangleCollider(60, 60, 0, 0);
	collidor->setOverlappable(false);
	addComponent(collidor);

	rb = new Rigidbody();
	addComponent(rb);

	auto tmp = getComponents<Collider>();
	tmp.pop_back();
}

void GameObject001::eventTick() {
	if (c.isKeyDown(Key::S)) {
		s_keyPressed = true;
	}
	else {
		s_keyPressed = false;
	}

	movement();
	rotation();
	shapeShift();
	shooting();
}

void GameObject001::movement() {
	if (c.isKeyDown(Key::RIGHT_ARROW)) {
		rb->addForce(Vector2::right() * (Time::getDeltaTime() * speed));
	}
	else if (c.isKeyDown(Key::LEFT_ARROW)) {
		rb->addForce(Vector2::left() * (Time::getDeltaTime() * speed));
	}

	if (c.isKeyDown(Key::UP_ARROW)) {
		rb->addForce(Vector2::up() * (Time::getDeltaTime() * speed));
	}
	else if (c.isKeyDown(Key::DOWN_ARROW)) {
		rb->addForce(Vector2::down() * (Time::getDeltaTime() * speed));
	}
}

void GameObject001::rotation()
{
	auto tmp = this->getTransform();
	if (c.isKeyDown(Key::Q)) {
		this->setTransform(Transform(tmp.position, tmp.rotationX - Time::getDeltaTime() * rotationSpeed));
	}
	else if (c.isKeyDown(Key::E)) {
		this->setTransform(Transform(tmp.position, tmp.rotationX + Time::getDeltaTime() * rotationSpeed));
	}
}

void GameObject001::shooting() {
	if (a_shootingSpeed <= 0 && c.isKeyDown(Key::SPACE)) {
		a_shootingSpeed = shootingSpeed;

		auto bullet = instantiate<GameObject002_Bullet>();
		bullet->setTransform(Transform(this->getWorldPosition()));
		bullet->setSortingLayer(1);
		
		auto bullet_rb = bullet->getComponent<Rigidbody>();

		Vector2 vec; 
		vec.setVectorByAngleAndLength(-getTransform().rotationX, 50);
		bullet_rb->addForce(vec); 
	}
	else if (a_shootingSpeed > 0) {
		a_shootingSpeed -= Time::getDeltaTime();
	}
}

void GameObject001::shapeShift()
{
	if (s_keyPressed && changeColor) {
		changeColor = false;

		aColor = !aColor;
		if (aColor) {
			rend->setColor(color2);
		}
		else {
			rend->setColor(color1);
		}
	}
	else if (!s_keyPressed) {
		changeColor = true;
	}
}
