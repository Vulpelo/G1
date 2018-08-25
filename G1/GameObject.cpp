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

void GameObject::mainBeginPlay()
{
}

void GameObject::mainEventTick(sf::Time deltaTime)
{
	Object::mainEventTick(deltaTime);
}

GameObject::~GameObject()
{
}
