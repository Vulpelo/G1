#pragma once

#ifndef _Actor_H_
#define _Actor_H_

#include "GameObject.h"
#include <vector>

class Actor : public GameObject
{
private:
	bool notMovingX;
	bool notMovingY;
	double actualMovementAngleX;

	void worldCoordinateMovement(); //Moving on screen

protected:
	/*=Movement=*/
	/*Speed of actor when movementToRotationDirection is true.
	Then meshes setRotateToMovementDirection should be false
	because this function uses speedRight and speedForward*/
	Vector2D actualMovement;
	bool movementToRotationDirection;
	double maxWalkSpeedForwad;//!-przeniesc do klasy wy¿ej
	double maxWalkSpeedRight;//!-przeniesc do klasy wy¿ej
	double movementAcceleration;
	double movementDecrementation;
	double rotationSpeed;//!-przeniesc do klasy wy¿ej

	std::vector <Object*> objectsToSpawn;
	bool havePlayerInput;
	ControlInput * playerInput;

	sf::Time deltaTime;

	float gravity;

	void movementDecrementacionF();
public:
	//clear virtual ------------------
	virtual void beginPlay() = 0;
	virtual void EventTick() = 0;
	//clear virtual ------------------

	Actor();
	Actor(double x, double y, double rotate);
	//Actor(Mesh a, double worldCoordinateX, double worldCoordinateY);

	//Event tick który ma podstawowe funkcje które siê zawsze wykunuja
	void mainEventTick(sf::Time deltaTime);
	void mainBeginPlay();


	std::vector <Object*> toSpawn();//THIS
	void spawnObject(Object*);//THIS
	void setPlayerInput(ControlInput * input);//THIS only for actor
	bool hasPlayerInput();//THIS only for actor

	void updateMesh();
	void movementAngle();
	//rate is from -1 to 1
	void movementForward(float rate);
	void movementRight(float rate);

	/*-=+=- Additional functions -=+=-*/

	/*Simple move this actor to position. Stop if distance between actor and 
	position is lower or equal distancePrecision*/
	bool simpleMoveTo(Position coordinate, double distancePrecision);

	/*Rotate mesh to given position with rotationSpeed. anglePrecision in degrees.*/
	bool lookAt(Component *m, Position point, double anglePrecision);
	/*Rotate simpleShape to given position with rotationSpeed. anglePrecision in degrees.*/
	bool lookAt(SimpleShape *s, Position point, double anglePrecision);
	/*Changes value of wTransform.rotationX and rotates it to given position with rotationSpeed. 
	anglePrecision in degrees.*/
	bool lookAt(Position point, double anglePrecision);
};

#endif // !_Actor_H_