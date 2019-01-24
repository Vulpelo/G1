//#include <iostream>
#include "Mesh.h"
//#include "SimpleShape.h"

Mesh::Mesh() {}

Mesh::Mesh(SimpleShape ** shapesZ, int numberOfShapesZ)
	:shapes(shapesZ), numberOfShapes(numberOfShapesZ),
	rotateToMovementDirection(false) 
{
	for (int i = 0; i < numberOfShapesZ; i++)
	{
		shapes[i]->setParent(this);
	}
}

Mesh::~Mesh()
{
	for (int i = 0; i < numberOfShapes; i++)
		delete shapes[i];
	delete[] shapes;
}

void Mesh::render(sf::RenderWindow * w)
{
	for (int i = 0; i < numberOfShapes; i++)
	{
		if (shapes[i] == NULL)
		{
			break;
		}
		else
		{
			shapes[i]->draw(w);
		}
	}
}

void Mesh::setPosition(double x, double y)
{
	transform.position.X = x;// +localPositionX;
	transform.position.Y = y;// +localPositionY;
	for (int i = 0; i < numberOfShapes; i++)
	{
		if (shapes[i] == NULL)
			break;
		else
		{
			shapes[i]->additionalMeshLocalPosition(localPositionX, localPositionY);
			shapes[i]->setWorldPosition(transform.position.X, transform.position.Y);
		}
	}
	if(collision != NULL)
		collision->setWorldPosition(transform.position.X, transform.position.Y);
}

void Mesh::setLocalPosition(double x, double y) 
{
	localPositionX = x;
	localPositionY = y;
	for (int i = 0; i < numberOfShapes; i++)
	{
		if (shapes[i] == NULL)
			break;
		else
		{
			shapes[i]->additionalMeshLocalPosition(localPositionX, localPositionY);
		}
	}
}

void Mesh::setRotation(double x)
{
	transform.rotationX = x;
	for (int i = 0; i < numberOfShapes; i++)
	{
		if (shapes[i] == NULL)
		{
			break;
		}
		else
		{
			shapes[i]->setWorldRotation(x);
		}
	}
	if (collision != NULL)
		collision->setWorldRotation(x);
}

void Mesh::setRotateToMovementDirection(bool a)
{
	this->rotateToMovementDirection = a;
}

bool Mesh::getRotateToMovementDirection()
{
	return rotateToMovementDirection;
}

//bool Mesh::collides(Collision *otherCollider)
//{
//	if(collision != NULL)
//		return collision->isCollidingWith(otherCollider);
//	return false;
//}

//Collision* Mesh::getCollider()
//{
//	return collision;
//}

void Mesh::setCollider(Collision *collider)
{
	this->collision = collider;
}

SimpleShape ** Mesh::getShapes()
{
	return shapes;
}