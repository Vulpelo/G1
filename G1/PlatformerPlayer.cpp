#include "PlatformerPlayer.h"



void PlatformerPlayer::beginPlay() {
	setLayer(Layer::PLAYER);

	jumpForce = 100.f;

	c = *ControlInput::getInstantiate();

	auto collidor = new RectangleCollider(40, 80, 0, 0);
	collidor->setOverlappable(false);
	addComponent(collidor);

	addComponent(rend);
	addComponent(rb);

	auto tmp = getComponents<Collider>();
	tmp.pop_back();
}

void PlatformerPlayer::eventTick() {
	if (c.isKeyDown(sf::Keyboard::Key::S)) {
		s_keyPressed = true;
	}
	else {
		s_keyPressed = false;
	}

	if (Physics::circleOverlaps(getWorldPosition() + Vector2::down() * 40.f, 1.f, static_cast<int>(Layer::GROUND)).empty() ) {
		grounded = false;
	}
	else {
		grounded = true;
	}

	//std::cout << grounded << std::endl;

	movement();
	shapeShift();
	shooting();

	std::cout << rb->getVelocity().x << ":" << rb->getVelocity().y << std::endl;
}

void PlatformerPlayer::movement() {
	if (c.isKeyDown(sf::Keyboard::Key::Right)) {
		targetMoveVelocity = Vector2::right();
	}
	else if (c.isKeyDown(sf::Keyboard::Key::Left)) {
		targetMoveVelocity = Vector2::left();
	}
	else {
		targetMoveVelocity.set(0, 0);
	}

	targetMoveVelocity.x *= maxSpeed;
	targetMoveVelocity.y = rb->getVelocity().y;
	rb->setVelocity(
		Vector2::smoothDump(rb->getVelocity(), targetMoveVelocity, actualMoveVelocity, smoothMove)
	);

	if (grounded && c.keyDown(sf::Keyboard::Key::Up)) {
		rb->addForce(Vector2::up() * jumpForce);
	}
	else if (c.keyUp(sf::Keyboard::Key::Up)) {
		rb->addForce(Vector2::up() * jumpForce);
	}
}


void PlatformerPlayer::shooting() {
	if (a_shootingSpeed <= 0 && c.isKeyDown(sf::Keyboard::Key::Space)) {
		a_shootingSpeed = shootingSpeed;

		auto bullet = instantiate<GameObject002_Bullet>();
		bullet->setTransform(Transform(this->getWorldPosition() + Vector2(50,0)));
		bullet->setSortingLayer(1);

		auto bullet_rb = bullet->getComponent<Rigidbody>();

		Vector2 vec = Vector2::right();
		vec = vec*50;
		bullet_rb->addForce(vec);
	}
	else if (a_shootingSpeed > 0) {
		a_shootingSpeed -= Time::getDeltaTime();
	}
}

void PlatformerPlayer::shapeShift()
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
