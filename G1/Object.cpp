#include "Object.h"

Object::Object()
{
	this->wTransform.position.X = 0;
	this->wTransform.position.Y = 0;
	this->wTransform.rotationX = 0;

	mainBeginPlay();
}

Object::Object(Transform nWTransform)
{
	this->wTransform = nWTransform;
	mainBeginPlay();
}

Object::~Object()
{
	for each (Component* c in components)
	{
		delete c;
	}
	components.clear();

	overlapingObjects.clear();
	newOverlapingObjects.clear();
}

std::vector<Object*>& Object::getOverlapingObjects()
{
	return overlapingObjects;
}

std::vector<Object*>& Object::getNewOverlapingObjects()
{
	return newOverlapingObjects;
}

void Object::addNewOverlapingObject(Object * overlaped)
{
	newOverlapingObjects.push_back(overlaped);
}

void Object::mainBeginPlay()
{
	layer = Layer::DEFAULT;
	this->lifeTime = 0;
	this->currentLifeTime = 0;
	this->destroyObject = false;

	setWorldCoordinate(this->wTransform.position.X, this->wTransform.position.Y);
	setWorldRotation(this->wTransform.rotationX);
	//Object::updateMesh();
}

void Object::mainEventTick(sf::Time deltaTime)
{
	if (lifeTime > 0.0 && currentLifeTime >= lifeTime) {
		this->destroyObject = true;
	}
	currentLifeTime += deltaTime.asSeconds();
}

void Object::updateMesh()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->setPosition(wTransform.position.X, wTransform.position.Y);
		components.at(i)->setRotation(wTransform.rotationX);
	}
}

void Object::render(sf::RenderWindow * w)
{
	for (unsigned int i = 0; i<components.size(); i++)
		components.at(i)->render(w);
}

Transform Object::get_wTransform()
{
	return this->wTransform;
}

void Object::set_wTransform(Transform nTran)
{
	wTransform = nTran;
}

std::vector <Component*> &Object::getComponents()
{
	return components;
}

void Object::setWorldCoordinate(double x, double y)
{
	for (unsigned int i = 0; i<components.size(); i++)
		components.at(i)->setPosition(x, y);
}

void Object::setWorldRotation(double x)
{
	for (unsigned int i = 0; i<components.size(); i++)
		components.at(i)->setRotation(x);
}

bool Object::shouldBeDestroyed()
{
	return this->destroyObject;
}

void Object::DestroyObject(float nlifeTime)
{
	this->lifeTime = this->currentLifeTime + nlifeTime;
}
