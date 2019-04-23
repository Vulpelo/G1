#include "GameObject.h"

namespace G1 {

	GameObject::GameObject()
	{
		this->transform.position.X = 0;
		this->transform.position.Y = 0;
		this->transform.rotationX = 0;

		//setRotation(this->transform.rotationX);
		//GameObject::updateMesh();

		layer = Layer::DEFAULT;
		this->lifeTime = 0;
		this->currentLifeTime = 0;
		this->toDestroy = false;
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

	void GameObject::instantiate(ISpawnable* spawnable)
	{
		GameObjectsData::addInstantiate(spawnable);
	}

	void GameObject::beginPlay()
	{
	}

	void GameObject::eventTick()
	{
	}

	void GameObject::mainBeginPlay()
	{
		beginPlay();
	}

	void GameObject::mainEventTick()
	{
		if (lifeTime > 0.0 && currentLifeTime >= lifeTime) {
			this->toDestroy = true;
		}
		currentLifeTime += Time::getDeltaTime();

		eventTick();
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

	void GameObject::destroy(float nlifeTime)
	{
		this->lifeTime = this->currentLifeTime + nlifeTime;
	}

	bool GameObject::shouldBeDestroyed()
	{
		return this->toDestroy;
	}

	std::vector <Component*> &GameObject::getComponents()
	{
		return components;
	}

	void GameObject::addComponent(Component * component)
	{
		component->setParent(this);
		components.push_back(component);
	}

}
