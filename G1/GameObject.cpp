#include "GameObject.h"

namespace G1 {

	GameObject::GameObject()
	{
		this->transform.position.X = 0;
		this->transform.position.Y = 0;
		this->transform.rotationX = 0;

		setWorldRotation(this->transform.rotationX);
		//GameObject::updateMesh();

		layer = Layer::DEFAULT;
		this->lifeTime = 0;
		this->currentLifeTime = 0;
		this->destroyObject = false;
		//setWorldCoordinate(this->transform.position.X, this->transform.position.Y);
	}

	GameObject::~GameObject()
	{
		for each (Component* c in components)
		{
			delete c;
		}
		components.clear();

		overlapingObjects.clear();
		newOverlapingObjects.clear();
	}

	void GameObject::beginPlay()
	{
	}

	void GameObject::eventTick()
	{
	}

	void GameObject::mainEventTick()
	{
		if (lifeTime > 0.0 && currentLifeTime >= lifeTime) {
			this->destroyObject = true;
		}
		currentLifeTime += Time::getDeltaTime();
	}

	void GameObject::updateMesh()
	{
		for (int i = 0; i < int(components.size()); i++)
		{
			components.at(i)->setPosition(transform.position.X, transform.position.Y);
			components.at(i)->setRotation(transform.rotationX);
		}
	}

	void GameObject::render(sf::RenderWindow * w)
	{
		for (unsigned int i = 0; i < components.size(); i++)
			components.at(i)->render(w);
	}

	void GameObject::addNewOverlapingObject(GameObject * overlaped)
	{
		newOverlapingObjects.push_back(overlaped);
	}

	std::vector<GameObject*>& GameObject::getOverlapingObjects()
	{
		return overlapingObjects;
	}

	std::vector<GameObject*>& GameObject::getNewOverlapingObjects()
	{
		return newOverlapingObjects;
	}

	Transform GameObject::getTransform()
	{
		return this->transform;
	}

	Vector2 GameObject::getWorldPosition()
	{
		Vector2 worldPos;

		GameObject *next = this;
		do {
			worldPos = worldPos + next->getTransform().position;
			next = next->getParent();
		} while (next != NULL);

		return worldPos;
	}

	void GameObject::setTransform(Transform nTran)
	{
		transform = nTran;
	}

	void GameObject::setWorldRotation(double x)
	{
		this->transform.rotationX = x;
	}

	GameObject * GameObject::getParent()
	{
		return parent;
	}

	void GameObject::setParent(GameObject * parent)
	{
		this->parent = parent;
	}

	void GameObject::DestroyObject(float nlifeTime)
	{
		this->lifeTime = this->currentLifeTime + nlifeTime;
	}

	bool GameObject::shouldBeDestroyed()
	{
		return this->destroyObject;
	}

	std::vector <Component*> &GameObject::getComponents()
	{
		return components;
	}

}
