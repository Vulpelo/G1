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

	void Rigidbody::setDrag(float drag)
	{ 
		if (drag < 0) this->drag = 0.0f; 
		else if (drag > 1.0f) this->drag = 1.f; 
		else this->drag = drag; 
	}

	Vector2 Rigidbody::getVelocity() const
	{
		return velocity;
	}

	void Rigidbody::setVelocity(Vector2 velocity)
	{
		this->velocity = velocity;
	}
}
