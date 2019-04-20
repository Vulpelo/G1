#include "GameObject001.h"


void GameObject001::beginPlay() {
	speed = 100.0f;
	shootingSpeed = 1.0f;
	a_shootingSpeed = 0.2f;
	aColor = false;
	
	color1 = sf::Color::Green;
	color2 = sf::Color::Blue;


	circleRend = new CircleRenderer(30, color1);

	addComponent(circleRend);
}

void GameObject001::eventTick() {
	movement();

	shooting();
}

void GameObject001::movement() {
	if (c.right_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X += Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.left_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X -= Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}

	if (c.up_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y -= Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.down_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y += Time::getDeltaTime() * speed;
		tran.position = pos;

		setTransform(tran);
	}
}

void GameObject001::shooting() {
	if (a_shootingSpeed <= 0 && c.space_KeyboardKeyPressed()) {
		a_shootingSpeed = shootingSpeed;

		auto bullet = new GameObject002_Bullet();
		instantiate(bullet);
		bullet->setTransform(Transform(this->getWorldPosition()));

		aColor = !aColor;
		if (aColor) {
			circleRend->setColor(color2);
		}
		else {
			circleRend->setColor(color1);
		}

	}
	else if (a_shootingSpeed > 0) {
		a_shootingSpeed -= Time::getDeltaTime();
	}
}
