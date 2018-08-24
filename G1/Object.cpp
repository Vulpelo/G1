#include "Object.h"

Object::Object()
{
	this->wTransform.position.X = 0;
	this->wTransform.position.Y = 0;
	this->destroyObject = false;
	mainBeginPlay();
}

Object::Object(Transform nWTransform)
{
	this->destroyObject = false;
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

	layers.clear();
	overlapingObjects.clear();
	newOverlapingObjects.clear();
}

void Object::mainBeginPlay()
{
	layers.insert(Layer::DEFAULT);

	setWorldCoordinate(this->wTransform.position.X, this->wTransform.position.Y);
	setWorldRotation(this->wTransform.rotationX);
	//Object::updateMesh();
}

void Object::mainEventTick(sf::Time deltaTime)
{
	if (lifeTime <= 0.0)
		this->destroyObject = false;
	else if (currentLifeTime >= lifeTime)
		this->destroyObject = true;

}

void Object::updateMesh()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->setPosition(wTransform.position.X, wTransform.position.Y);
		//components.at(i)->setRotation(wTransform.rotationX);
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

void Object::DestroyObject()
{
	this->destroyObject = true;
}
