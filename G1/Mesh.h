#pragma once

#ifndef _Mesh_H_
#define _Mesh_H_

#include "Component.h"

class Mesh : public Component
{
private:
	//Collision * collision;
	SimpleShape ** shapes;
	int numberOfShapes;
	bool rotateToMovementDirection;
public:
	Mesh();
	Mesh(SimpleShape ** shapesZ, int numberOfShapesZ);
	void render(sf::RenderWindow *);
	//bool collides(Collision *otherCollider);
	//Collision* getCollider();
	void setCollider(Collision *collider);
	void setPosition(double, double);
	void setLocalPosition(double, double);
	void setRotation(double);
	void setRotateToMovementDirection(bool a);
	bool getRotateToMovementDirection();
	//simple shapes that are rendered
	SimpleShape ** getShapes();
};

#endif // !_Mesh_H_
