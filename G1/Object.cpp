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

bool Object::isCollidingObjectM(Object *otherObject) const
{
	std::vector <Component*> otherComponents = otherObject->getComponents();

	bool objectCollides = false;

	for (unsigned int i = 0; i < otherComponents.size(); i++)
	{
		for (unsigned int j = 0; j < components.size(); j++)
		{
			if(otherComponents.at(i)->getCollider() != NULL && components.at(j)->getCollider() !=NULL)
				if (components.at(j)->collides(otherComponents.at(i)->getCollider()))
					return true;//-  
					/*{
					components.at(j)->addOverlapComponent(otherComponents.at(i));
					components.at(i)->addOverlapComponent(otherComponents.at(j));
					objectCollides = true;
					}*/

			// TODO: Trzeba dorobic ogolne eventy dla kazdego mesha a nie dla calego objektu
		}
	}
	return false;//-
	/*return objectCollides;*/
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

void Object::overlapingMain(Object *overlaped)
{
	newOverlapingObjects.push_back(overlaped);
}

void Object::overlapingEndMain()
{
	for (int i = 0; i < components.size(); i++)
	{
		//Object* obj = this;
		components.at(i)->overlapingEndMain();
		for(int i=0; i < components.at(i)->getStartOverlapingComp().size(); i++)
		{
			startOverlapingComponent(components.at(i)->getName(), components.at(i)->getStartOverlapingComp()[i]);
		}
		for (int i = 0; i < components.at(i)->getIsOverlapingComp().size(); i++)
		{
			isOverlapingComponent(components.at(i)->getName(), components.at(i)->getIsOverlapingComp()[i]);
		}
		for (int i = 0; i < components.at(i)->getEndOverlapingComp().size(); i++)
		{
			endOverlapingComponent(components.at(i)->getName(), components.at(i)->getEndOverlapingComp()[i]);
		}
	}

	for (int i = 0; i < overlapingObjects.size(); i++)
	{
		bool overlaping = false;
		int j = 0;
		for (j = 0; j < newOverlapingObjects.size(); j++)
		{
			if (overlapingObjects.at(i) == newOverlapingObjects.at(j))
			{
				//czyli isOverlaping
				overlaping = true;
				break;
			}
		}

		if (overlaping == false)
		{
			endOverlaping(overlapingObjects.at(i));
			overlapingObjects.erase(overlapingObjects.begin() + i--);
		}
		else
		{
			isOverlaping(overlapingObjects.at(i));
			if (!newOverlapingObjects.empty())
				newOverlapingObjects.erase(newOverlapingObjects.begin() + j);
		}
	}
	for (int i = 0; i < newOverlapingObjects.size(); i++)
	{
		startOverlaping(newOverlapingObjects.at(i));
		overlapingObjects.push_back(newOverlapingObjects.at(i));
	}
	newOverlapingObjects.clear();
}

void Object::DestroyObject()
{
	this->destroyObject = true;
}
