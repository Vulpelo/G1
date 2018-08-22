#include "Object.h"

Object::Object()
{
	this->wTransform.position.X = 0;
	this->wTransform.position.Y = 0;
	this->destroyObject = false;
	mainBeginPlay();
}

Object::Object(double x, double y, double rotate)
{
	this->destroyObject = false;
	this->wTransform.position.X = x;
	this->wTransform.position.Y = y;
	this->wTransform.rotationX = rotate;
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

void Object::beginPlay()
{
	setWorldCoordinate(this->wTransform.position.X, this->wTransform.position.Y);
	setWorldRotation(this->wTransform.rotationX);
}

void Object::render(sf::RenderWindow * w)
{
	for (unsigned int i = 0; i<components.size(); i++)
		components.at(i)->render(w);
}

std::vector <Component*> Object::getComponents() const
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
