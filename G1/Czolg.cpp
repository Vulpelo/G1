#include "Czolg.h"



Czolg::Czolg(Transform nWTransform)
	:Player(nWTransform)
{
	beginPlay();
}

Czolg::Czolg()
	: Player()
{
	beginPlay();
}


void Czolg::beginPlay()
{
	this->maxWalkSpeedForwad = 100;
	this->maxWalkSpeedRight = 100;
	this->rotationSpeed = 100;
	this->havePlayerInput = true;
	this->movementToRotationDirection = true;
	this->movementAcceleration = 100;
	this->movementDecrementation = 150;
	this->shootRate = 1;
	this->aShootRate = 0;



	int nrOfShapes = 2;
	SimpleShape **sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(54, 75, sf::Color(0, 0, 255, 255));
	sS[1] = new Rectangle(40, 75, sf::Color(0, 255, 0, 255));
	Mesh * m = new Mesh(sS, nrOfShapes);
	m->setName("Body");
	Collision *c = new CollisionRectangle(54, 54, 0, 0);
	m->setCollider(c);
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	nrOfShapes = 2;
	sS = new SimpleShape*[nrOfShapes];
	sS[0] = new Rectangle(30,40, sf::Color(255, 0, 0, 255));
	sS[1] = new Rectangle(10, 40, sf::Color(255, 0, 0, 255));
	sS[1]->setLocalCoordinate(0, 20);
	m = new Mesh(sS, nrOfShapes);
	m->setLocalPosition(0, 0);
	m->setName("Gun");
	m->setRotateToMovementDirection(false);
	this->components.push_back(m);

	updateMesh();
}

void Czolg::EventTick()
{
	movement();
	//rotation
	/*this->wTransform.rotationX = GMath::twoPointsAngle
	(this->wTransform.position.X, this->wTransform.position.Y,
		this->playerInput->mousePosition().x, -this->playerInput->mousePosition().y);*/

	//components.at(2)->setLocalRotation(rot - components.at(2)->getXWorldRotation());

	if (playerInput->a_KeyboardKeyPressed())
	{
		this->wTransform.rotationX -= deltaTime.asSeconds() * rotationSpeed;
	}
	if (playerInput->d_KeyboardKeyPressed())
	{
		this->wTransform.rotationX += deltaTime.asSeconds() * rotationSpeed;
	}

	//shooting
	if (playerInput->space_KeyboardKeyPressed())//|| playerInput->leftMouseButtonPressed())
	{
		if (this->aShootRate <= 0)
		{
			this->aShootRate = this->shootRate;

			Transform nTran(this->get_wTransform().position);
			nTran.rotationX = this->wTransform.rotationX;

			Vector2D offset; offset.setVectorByAngleAndLength(nTran.rotationX, -50);
			nTran.position = nTran.position - offset;

			spawnObject(new Bullet(nTran));
		}
	}
	aShootRate -= deltaTime.asSeconds();

}


void Czolg::movement()
{
	//movement
	if (playerInput->w_KeyboardKeyPressed() || playerInput->s_KeyboardKeyPressed())
	{
		if (playerInput->w_KeyboardKeyPressed())
			movementForward(1);
		else if (playerInput->s_KeyboardKeyPressed())
			movementForward(-1);
	}
	else
		movementForward(0);
	//if (playerInput->d_KeyboardKeyPressed() || playerInput->a_KeyboardKeyPressed())
	//{
	//	if (playerInput->d_KeyboardKeyPressed())
	//		movementRight(1);
	//	else if (playerInput->a_KeyboardKeyPressed())
	//		movementRight(-1);
	//}
	//else
	//	movementRight(0);
}

