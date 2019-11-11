#include "Transformable.h"

namespace G1 {
	Transformable& Transformable::getTopParent()
	{
		Transformable *next = this;
		while (next->getParent() != NULL) {
			next = next->getParent();
		}
		return *next;
	}

	void Transformable::setPosition(float x, float y)
	{
		this->transform.position.x = x;
		this->transform.position.y = y;
	}

	void Transformable::setPosition(const Vector2& position)
	{
		this->transform.position.x = position.x;
		this->transform.position.y = position.y;
	}

	void Transformable::move(float x, float y)
	{
		this->transform.position.x += x;
		this->transform.position.y += y;
	}

	void Transformable::move(const Vector2 & moveBy)
	{
		this->transform.position += moveBy;
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
	Vector2 Transformable::getWorldScale()
	{
		Vector2 worldScale = this->transform.scale;

		Transformable *next = this->getParent();
		Vector2 scaleTmp;
		do {
			scaleTmp = next->getTransform().scale;
			worldScale.x *= scaleTmp.x;
			worldScale.y *= scaleTmp.y;
			next = next->getParent();
		} while (next != NULL);

		return worldScale;
	}
}
