#include "Rigidbody.h"

namespace G1 {

	Rigidbody::Rigidbody()
	{
	}


	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::mainEventTick()
	{
		Transform tran = this->getParent()->getTransform();
		tran.position = tran.position + (velocity * Time::getDeltaTime());

		this->getParent()->setTransform(tran);
	}

	void Rigidbody::addForce(Vector2 force)
	{
		velocity = velocity + force;
	}

	Vector2 Rigidbody::getVelocity()
	{
		return velocity;
	}

	void Rigidbody::setVelocity(Vector2 velocity)
	{
		this->velocity = velocity;
	}
}
