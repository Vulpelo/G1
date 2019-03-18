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

		return transform.position;
	}

	void Transformable::setTransform(Transform transform)
	{
		this->transform = transform;
	}

	Transform Transformable::getTransform()
	{
		return this->transform;
	}
	
	void Transformable::setRotation(float x)
	{
		transform.rotationX = x;
	}

}
