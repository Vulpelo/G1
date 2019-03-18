#pragma once

#ifndef _GameObject_H_
#define _GameObject_H_

#include "ControlInput.h"
#include "Layer.h"
#include "Transform.h"
#include "Component.h"
#include "Time.h"

// containers
#include <vector>
#include <set>

namespace G1 {

	class GameObject
	{
		friend class GameMap;
		friend class RenderManager;

		GameObject* parent;

		// Displays object's components on screen
		void render(sf::RenderWindow * w);

		//collision interactions (interacts any of objects components)
		std::vector <GameObject *> overlapingObjects;
		std::vector <GameObject *> newOverlapingObjects;

		std::vector<GameObject*>& getOverlapingObjects();
		void addNewOverlapingObject(GameObject* overlaped);

		//GameObject distruct
		bool destroyObject;
		float currentLifeTime;
		float lifeTime;
	protected:
#pragma region protected Variables
		int layer;

		std::vector <Component*> components;
		// transform related to parent
		Transform transform;

		std::vector<GameObject*>& getNewOverlapingObjects();

		//Mesh/Components
#pragma endregion

		virtual void mainEventTick();
		virtual void updateMesh();

	public:
		GameObject();

		GameObject* getParent();
		void setParent(GameObject* parent);

		virtual ~GameObject();

		/// <summary>Function played at the begining when object is created</summary>
		virtual void beginPlay();

		/// <summary>Function if played every frame of object life span</summary>
		virtual void eventTick();

#pragma region set/get functions
		/// <summary>Return's reference to container with all GameObject's components</summary>
		std::vector <Component*> &getComponents();

		Transform getTransform();

		/// <summary> Returns copy of world Transform of this object in world space</summary>
		Vector2 getWorldPosition();

		/// <summary> Sets world Transform of this object in world space</summary>
		void setTransform(Transform);

		/// <summary>Sets rotation of an object in world wide</summary>
		void setWorldRotation(double x);
#pragma endregion

#pragma region Overlaping interactions
		/// <summary>Function is called every time when new object just touched this object</summary>
		virtual void startOverlaping(GameObject *overlaped) {};

		/// <summary>Function is called every time when some object is still coliding with this object</summary>
		virtual void isOverlaping(GameObject *overlaped) {};

		/// <summary>Function is called every time when some object is no longer coliding with this object</summary>
		virtual void endOverlaping(GameObject *overlaped) {};

		//chosen parts of this object are touching other parts of other object
		virtual void startOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
		virtual void isOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
		virtual void endOverlapingComponent(std::string nameComponent, Component *overlapedComponent) {};
#pragma endregion

		/// <summary>Destroys object before next tick</summary>
		void DestroyObject(float nlifeTime = 0.);

		/// <summary>Checks if object is going to be destroyed</summary>
		bool shouldBeDestroyed();






	};

}

#endif // !_GameObject_H_
