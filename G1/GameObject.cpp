#include "GameObject.h"

namespace G1 {

	GameObject::GameObject()
	{
		this->transform.position.x = 0;
		this->transform.position.y = 0;
		this->transform.rotationX = 0;

		sortingLayer = 0;
		layer = Layer::DEFAULT;
		
		this->lifeTime = 0;
		this->currentLifeTime = 0;
		this->toDestroy = false;
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

	Layer GameObject::getLayer()
	{
		return layer;
	}

	void GameObject::setLayer(Layer layer)
	{
		this->layer = layer;
	}

	bool GameObject::inLayer(int layer)
	{
		return (layer & static_cast<int>(this->layer)) != 0;
	}

	bool GameObject::isLayer(Layer layer)
	{
		return this->layer == layer;
	}

	void GameObject::setSortingLayer(int sortingLayer)
	{
		this->sortingLayer = sortingLayer;
		GameObjectsData::updateSortingLayer(this);
	}

	int GameObject::getSortingLayer()
	{
		return this->sortingLayer;
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

		this->eventTick();

		for each (Component* component in components) {
			if (component->isEnabled()) {
				component->mainEventTick();
			}
		}
	}
	
	void GameObject::render(sf::RenderWindow * w)
	{
		for each (Component* component in components)
		{
			if (component->isEnabled()) {
				component->render(w);
			}
		}
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

	/// <summary>
	/// Adds another component to this GameObject.
	/// Order of adding components is important for Renderers
	/// </summary>
	/// <param name="component"></param>
	void GameObject::addComponent(Component * component)
	{
		components.push_back(component);

		auto transformableComponent = dynamic_cast<Transformable*>(component);
		if (transformableComponent) {
			transformableComponent->setParent(this);
		}
	}

}
