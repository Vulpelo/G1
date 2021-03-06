#include "PlatformerPlayer.h"

void PlatformerPlayer::startPlay() {
	setLayer(Layer::PLAYER);

	/* == COLLIDERS == */
	/* Setting Collider (will be allways active) */
	auto collidor = new RectangleCollider(16, 16, 0, 8);
	collidor->setOverlappable(false);
	addComponent(collidor);

	/* Setting crouch Collider (will not be enabled when player is crouching) */
	crouchCollider = new RectangleCollider(16, 6, 0, -3);
	crouchCollider->setOverlappable(false);
	addComponent(crouchCollider);

	/* Overlappable collider for checking if entering other overlappable colliders*/
	collidor = new RectangleCollider(16, 24, 0, 0);
	collidor->setOverlappable(true);
	addComponent(collidor);

	/* == SPRITES AND ANIMATION == */
	/* Sprite that will be modifyied when animation is playing. Adding it as component */
	Sprite* renderSprite = new Sprite(texture, Vector2(33, 32));
	addComponent(renderSprite);

	/* Creating Animator and adding renderSprite.
	Animator will use 'renderSprite' as an output of SpriteAnimaton */
	animator = new PlayerAnimator(*renderSprite);
	addComponent(animator);

	/* == OTHER COMPONENTS CREATED IN DECLARATION == */
	/* Adding other components created in class declaration */
	rb->setGravity(gravity);
	addComponent(rb);

	/* == CAMERA == */
	/* Setting Camera Component*/
	Camera* camera = new Camera();
	camera->setActive(true);
	camera->setZoom(0.5f);
	addComponent(camera);
}

void PlatformerPlayer::beginPlay() {

	jumpForce = 200.f;

	/*rend = new RectangleRenderer(16, 16, color1);
	rend->setPosition(0.f, 5.f);
	addComponent(rend);
*/
}

void PlatformerPlayer::eventTick() {
	if (Physics::circleOverlaps(getWorldPosition() + Vector2::down() * 15.f, 1.5f, static_cast<int>(Layer::GROUND)).empty() ) {
		grounded = false;
	}
	else {
		grounded = true;
	}

	movement();
	animating();

	if (c.keyDown(sf::Keyboard::Key::R)) {
		MapManager::getInstance().reloadActual();
	}
}

void PlatformerPlayer::startOverlapping(GameObject * gameObject)
{
	if (gameObject->isLayer(Layer::CLIMBABLE)) {
		canClimb = true;
	}
}

void PlatformerPlayer::endOverlapping(GameObject * gameObject)
{
	if (gameObject->isLayer(Layer::CLIMBABLE)) {
		canClimb = false;
		climbing = false;
		rb->setGravity(gravity);
	}
}

void PlatformerPlayer::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0) {
		GameMaster::restart();
	}
}

void PlatformerPlayer::bounce()
{
	Vector2 v = rb->getVelocity();
	v.y = 0;
	rb->setVelocity(v);
	rb->addForce(Vector2::up() * enemyBonceVal);
}

void PlatformerPlayer::movement() {
	if (climbing) {
		if (c.isKeyDown(sf::Keyboard::Key::Up)) {
			targetMoveVelocity = Vector2::up();
		}
		else if (c.isKeyDown(sf::Keyboard::Key::Down)) {
			targetMoveVelocity = Vector2::down();
		}
		else if (c.isKeyDown(sf::Keyboard::Key::Left)) {
			targetMoveVelocity = Vector2::left();
		}
		else if (c.isKeyDown(sf::Keyboard::Key::Right)) {
			targetMoveVelocity = Vector2::right();
		}
		else {
			targetMoveVelocity.set(0, 0);
		}
		targetMoveVelocity *= maxSpeed;
		rb->setVelocity(targetMoveVelocity);
	}
	else if (canClimb) {
		if (c.keyDown(sf::Keyboard::Key::Up)) {
			climbing = true;
			rb->setGravity(Vector2(0, 0));
		}
	}

	if (!climbing) {
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
		rb->setVelocity(targetMoveVelocity);

		if (grounded && c.keyDown(sf::Keyboard::Key::Up)) {
			climbing = false;
			rb->addForce(Vector2::up() * jumpForce);
		}

		if (c.keyDown(sf::Keyboard::Key::Down)) {
			crouched = true;
			crouchCollider->setEnabled(false);
		}
		else if (c.keyUp(sf::Keyboard::Key::Down)) {
			crouched = false;
			crouchCollider->setEnabled(true);
		}
	}
}

void PlatformerPlayer::animating() {
	if (targetMoveVelocity.x > 0) {
		animator->setBool("running", true);
		if (!lookingRight) {
			flip();
		}
	}
	else if (targetMoveVelocity.x < 0) {
		animator->setBool("running", true);
		if (lookingRight) {
			flip();
		}
	}
	else {
		animator->setBool("running", false);
	}
	animator->setBool("grounded", grounded);
	animator->setBool("crouched", crouched);
	animator->setBool("climbing", climbing);
	animator->setBool("moving", targetMoveVelocity.nonZero());
}

void PlatformerPlayer::flip()
{
	lookingRight = !lookingRight;
	setScale(getTransform().scale.x * -1, getTransform().scale.y);
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
