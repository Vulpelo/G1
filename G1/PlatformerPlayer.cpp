#include "PlatformerPlayer.h"



void PlatformerPlayer::beginPlay() {
	setLayer(Layer::PLAYER);

	jumpForce = 100.f;

	c = *ControlInput::getInstantiate();

	/* == COLLIDERS == */
	/* Setting Collider (will be allways active) */
	auto collidor = new RectangleCollider(40, 40, 0, 20);
	collidor->setOverlappable(false);
	addComponent(collidor);

	/* Setting crouch Collider (will not be enabled when player is crouching) */
	crouchCollider = new RectangleCollider(40, 40, 0, -20);
	crouchCollider->setOverlappable(false);
	addComponent(crouchCollider);

	
	/* == SPRITES AND ANIMATION == */
	/* Sprite that will be modifyied when animation is playing. Adding it as component */
	Sprite* renderSprite = new Sprite(texture, Vector2(33, 32));
	addComponent(renderSprite);

	/* Creating Animator and adding renderSprite. 
		Animator will use 'renderSprite' as an output of SpriteAnimaton */

	animator = new PlayerAnimator(*renderSprite);
	addComponent(animator);


	/* == CAMERA == */
	/* Setting Camera Component*/
	Camera* camera = new Camera(Vector2(500, 400));
	camera->setActive(true);
	addComponent(camera);


	/* == OTHER COMPONENTS CREATED IN DECLARATION == */
	/* Adding other components created in class declaration */
	//addComponent(rend);
	addComponent(rb);
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

	movement();
	shapeShift();
	shooting();

	std::cout << rb->getVelocity().x << ":" << rb->getVelocity().y << std::endl;
}

void PlatformerPlayer::movement() {
	if (c.isKeyDown(sf::Keyboard::Key::Right)) {
		targetMoveVelocity = Vector2::right();
		animator->setBool("running", true);
	}
	else if (c.isKeyDown(sf::Keyboard::Key::Left)) {
		targetMoveVelocity = Vector2::left();
		animator->setBool("running", true);
	}
	else {
		targetMoveVelocity.set(0, 0);
		animator->setBool("running", false);
	}

	targetMoveVelocity.x *= maxSpeed;
	targetMoveVelocity.y = rb->getVelocity().y;
	rb->setVelocity(targetMoveVelocity
//		Vector2::smoothDump(rb->getVelocity(), targetMoveVelocity, actualMoveVelocity, smoothMove)
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
