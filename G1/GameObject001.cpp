#include "GameObject001.h"


void GameObject001::beginPlay() {
	CircleRenderer* cRend = new CircleRenderer(30, sf::Color::Green);

	addComponent(cRend);

	speed = 100.0f;
	shootingSpeed = 0.2f;
	a_shootingSpeed = 0.2f;
}

void GameObject001::eventTick() {
	//Transform tran = getTransform();
	//Vector2 pos = tran.position;
	//pos.X += Time::getDeltaTime() * 10.0f;
	//tran.position = pos;

	//std::cout << pos.X << std::endl;

	//setTransform(tran);
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
	}
	else if (a_shootingSpeed > 0) {
		a_shootingSpeed -= Time::getDeltaTime();
	}
}
