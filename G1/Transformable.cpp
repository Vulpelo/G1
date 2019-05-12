#include "Transformable.h"

namespace G1 {

	void Transformable::setPosition(float x, float y)
	{
		this->transform.position.X = x;
		this->transform.position.Y = y;
	}

	Vector2 Transformable::getWorldPosition()
	{
		Vector2 worldPos;

		Transformable *next = this;
		do {
			worldPos = worldPos + next->getTransform().position;
			next = next->getParent();
		} while (next != NULL);

		return worldPos;
	}

	void Transformable::setTransform(Transform transform)
	{
		this->transform = transform;
	}

	Transform Transformable::getTransform()
	{
		return this->transform;
	}

	float Transformable::getWorldRotation()
	{
		float worldRotation = 0;

		Transformable *next = this;
		do {
			worldRotation = worldRotation + next->getTransform().rotationX;
			next = next->getParent();
		} while (next != NULL);

		return worldRotation;
	}
	
	void Transformable::setRotation(float x)
	{
		transform.rotationX = x;
	}

}
