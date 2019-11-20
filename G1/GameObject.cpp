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
		for (size_t i = 0 ; i < components.size(); i++)
		{
			delete components[i];
		}
		components.clear();

		overlapingObjects.clear();
		newOverlapingObjects.clear();
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

	void GameObject::mainStartPlay()
	{
		this->startPlay();

		for each (Component* component in components) {
			if (component->isEnabled()) {
				component->mainStartPlay();
			}
		}
	}

	void GameObject::mainBeginPlay()
	{
		this->beginPlay();

		for each (Component* component in components) {
			if (component->isEnabled()) {
				component->mainBeginPlay();
			}
		}
	}

	void GameObject::mainEventTick()
	{
		if (lifeTime > 0.0 && currentLifeTime >= lifeTime) {
			this->toDestroy = true;
		}
		currentLifeTime += Time::getDeltaTime();

		this->eventTick();
	}

	void GameObject::mainFixedEventTick()
	{
		this->fixedEventTick();
	}

	void GameObject::mainEventTickComponents()
	{
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

		auto parentableComponent = dynamic_cast<Parentable*>(component);
		if (parentableComponent) {
			parentableComponent->setParent(this);
		}
	}

}
