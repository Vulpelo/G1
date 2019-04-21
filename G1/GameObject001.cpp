#include "GameObject001.h"


void GameObject001::beginPlay() {
	speed = 100.0f;
	shootingSpeed = 1.0f;
	a_shootingSpeed = 0.2f;
	aColor = false;
	changeColor = false;

	color1 = sf::Color::Yellow;
	color2 = sf::Color::Blue;


	circleRend = new CircleRenderer(30, color1);
	addComponent(circleRend);

	auto collidor = new CollisionCircle(30, 0, 0);
	addComponent(collidor);
}

void GameObject001::eventTick() {
	if (c.isKeyDown(Key::S)) {
		s_keyPressed = true;
	}
	else {
		s_keyPressed = false;
	}

	movement();
	shapeShift();
	shooting();
}

void GameObject001::movement() {
	if (c.isKeyDown(Key::RIGHT_ARROW)) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X += Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.isKeyDown(Key::LEFT_ARROW)) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X -= Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}

	if (c.isKeyDown(Key::UP_ARROW)) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y -= Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.isKeyDown(Key::DOWN_ARROW)) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y += Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
}

void GameObject001::shooting() {
	if (a_shootingSpeed <= 0 && c.isKeyDown(Key::SPACE)) {
		a_shootingSpeed = shootingSpeed;

		auto bullet = new GameObject002_Bullet();
		instantiate(bullet);
		bullet->setTransform(Transform(this->getWorldPosition()));
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
			circleRend->setColor(color2);
		}
		else {
			circleRend->setColor(color1);
		}
	}
	else if (!s_keyPressed) {
		changeColor = true;
	}
}
