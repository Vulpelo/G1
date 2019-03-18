#include "GameObject001.h"


void GameObject001::beginPlay() {
	CircleRenderer* cRend = new CircleRenderer(30, sf::Color::Green);

	addComponent(cRend);
}

void GameObject001::eventTick() {
	//Transform tran = getTransform();
	//Vector2 pos = tran.position;
	//pos.X += Time::getDeltaTime() * 10.0f;
	//tran.position = pos;

	//std::cout << pos.X << std::endl;

	//setTransform(tran);
	ControlInput c;

	if (c.right_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X += Time::getDeltaTime() * 10.0f;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.left_KeyboardKeyPressed()){
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.X -= Time::getDeltaTime() * 10.0f;
		tran.position = pos;

		setTransform(tran);
	}

	if (c.up_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y -= Time::getDeltaTime() * 10.0f;
		tran.position = pos;

		setTransform(tran);
	}
	else if (c.down_KeyboardKeyPressed()) {
		Transform tran = getTransform();
		Vector2 pos = tran.position;
		pos.Y += Time::getDeltaTime() * 10.0f;
		tran.position = pos;

		setTransform(tran);
	}
}
