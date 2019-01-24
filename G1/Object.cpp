#include "Object.h"

Object::Object()
{
	this->transform.position.X = 0;
	this->transform.position.Y = 0;
	this->transform.rotationX = 0;

	mainBeginPlay();
}

Object::Object(Transform nWTransform)
{
	this->transform = nWTransform;
	mainBeginPlay();
}

Object::~Object()
{
	overlapingObjects.clear();
	newOverlapingObjects.clear();
}



void Object::mainBeginPlay()
{
	setWorldRotation(this->transform.rotationX);
	//Object::updateMesh();
}

void Object::mainEventTick(sf::Time deltaTime)
{

}

Transform Object::get_wTransform()
{
	return this->transform;
}

void Object::set_wTransform(Transform nTran)
{
	transform = nTran;
}

void Object::setWorldRotation(double x)
{
	this->transform.rotationX = x;
}

void Object::setParent(Object * parent)
{
	this->parent = parent;
}

