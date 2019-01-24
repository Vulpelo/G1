#include "GameObject.h"





GameObject::GameObject()
	: Object()
{
	mainBeginPlay();
}

GameObject::GameObject(Transform nWTransform)
	: Object(nWTransform)
{
	mainBeginPlay();
}

void GameObject::render(sf::RenderWindow * w)
{
	for (unsigned int i = 0; i<components.size(); i++)
		components.at(i)->render(w);
}

void GameObject::updateMesh()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->setPosition(transform.position.X, transform.position.Y);
		components.at(i)->setRotation(transform.rotationX);
	}
}

std::vector<Object*>& GameObject::getOverlapingObjects()
{
	return overlapingObjects;
}

std::vector<Object*>& GameObject::getNewOverlapingObjects()
{
	return newOverlapingObjects;
}

void GameObject::addNewOverlapingObject(Object * overlaped)
{
	newOverlapingObjects.push_back(overlaped);
}

void GameObject::mainBeginPlay()
{
	layer = Layer::DEFAULT;
	this->lifeTime = 0;
	this->currentLifeTime = 0;
	this->destroyObject = false;
	//setWorldCoordinate(this->transform.position.X, this->transform.position.Y);
}

void GameObject::mainEventTick(sf::Time deltaTime)
{
	Object::mainEventTick(deltaTime);
	if (lifeTime > 0.0 && currentLifeTime >= lifeTime) {
		this->destroyObject = true;
	}
	currentLifeTime += deltaTime.asSeconds();
}

std::vector <Component*> &GameObject::getComponents()
{
	return components;
}

bool GameObject::shouldBeDestroyed()
{
	return this->destroyObject;
}

void GameObject::DestroyObject(float nlifeTime)
{
	this->lifeTime = this->currentLifeTime + nlifeTime;
}

GameObject::~GameObject()
{
	for each (Component* c in components)
	{
		delete c;
	}
	components.clear();
}


