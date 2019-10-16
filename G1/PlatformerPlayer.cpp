#include "PlatformerPlayer.h"



void PlatformerPlayer::beginPlay() {
	setLayer(Layer::PLAYER);

	jumpForce = 100.f;

	c = *ControlInput::getInstantiate();

	auto collidor = new RectangleCollider(40, 40, 0, 20);
	collidor->setOverlappable(false);
	addComponent(collidor);

	crouchCollider = new RectangleCollider(40, 40, 0, -20);
	crouchCollider->setOverlappable(false);

	if (!texture.loadFromFile("./assets/spritesheets/player-idle.png")) {
	}
	
	auto rendTex = new Sprite(texture, Vector2(33, 32));

	addComponent(rend);
	addComponent(rendTex);

	addComponent(crouchCollider);
	addComponent(rb);

	Camera* camera = new Camera(Vector2(500, 400));
	camera->setActive(true);
	addComponent(camera);
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

	if (c.isKeyDown(sf::Keyboard::Key::Down)) {
		Vector2 v(rb->getVelocity().x, 100.f);
		rb->setVelocity(v);
	}

	if (c.keyDown(sf::Keyboard::Key::Down)) {
		crouchCollider->setEnabled(false);
	}
	else if (c.keyUp(sf::Keyboard::Key::Down)) {
		crouchCollider->setEnabled(true);
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
