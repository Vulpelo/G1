#include "PlatformerPlayer.h"



void PlatformerPlayer::beginPlay() {
	setLayer(Layer::PLAYER);

	jumpForce = 50.f;

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
	if (c.isKeyDown(Key::S)) {
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
}

void PlatformerPlayer::movement() {
	if (c.isKeyDown(Key::RIGHT_ARROW)) {
		targetMoveVelocity = Vector2::right();
		//rb->addForce(Vector2::right() * (Time::getDeltaTime() * speed));
	}
	else if (c.isKeyDown(Key::LEFT_ARROW)) {
		targetMoveVelocity = Vector2::left();
		//rb->addForce(Vector2::left() * (Time::getDeltaTime() * speed));
	}
	else {
		targetMoveVelocity.set(0, 0);
	}

	targetMoveVelocity.x *= maxSpeed;
	targetMoveVelocity.y = rb->getVelocity().y;
	rb->setVelocity(
		Vector2::smoothDump(rb->getVelocity(), targetMoveVelocity, actualMoveVelocity, smoothMove)
	);


	if (grounded && c.isKeyDown(Key::UP_ARROW)) {
		rb->addForce(Vector2::up() * jumpForce);
	}
	else if (c.isKeyDown(Key::DOWN_ARROW)) {
		//rb->addForce(Vector2::down() * (Time::getDeltaTime() * speed));
	}
}


void PlatformerPlayer::shooting() {
	if (a_shootingSpeed <= 0 && c.isKeyDown(Key::SPACE)) {
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
