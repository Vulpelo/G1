#pragma once

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "ControlInput.h"
#include "Layer.h"

#include "Transformable.h"
#include "Component.h"
#include "ISpawnable.h"

#include "GameObjectsData.h"

#include "Time.h"

// containers
#include <vector>
#include <set>

namespace G1 {

	class GameObject : public ISpawnable, public Transformable
	{
		friend class GameMap;
		friend class RenderManager;
		friend class CollisionDetection;
		friend class OverlapingGameObjectsStates;

		// transform related to parent
		Transform transform;

		Layer layer;
		int sortingLayer;
		
		bool toDestroy;
		float currentLifeTime;
		float lifeTime;
		
		std::vector <Component*> components;

		//collision interactions (interacts any of objects components)
		std::vector <GameObject *> overlapingObjects;
		std::vector <GameObject *> newOverlapingObjects;

		std::vector<GameObject*>& getNewOverlapingObjects();
		std::vector<GameObject*>& getOverlapingObjects();
		void addNewOverlapingObject(GameObject* overlaped);

		// Displays object's components on screen
		void render(sf::RenderWindow * w);

		virtual void mainBeginPlay();
		virtual void mainEventTick();

	public:
		GameObject();
		~GameObject();

		/// <summary>Function played at the begining when object is created</summary>
		virtual void beginPlay();

		/// <summary>Function if played every frame of object life span</summary>
		virtual void eventTick();

#pragma region Layer
		/// <summary>Returns layer</summary>
		Layer getLayer();

		/// <summary>Sets new layer</summary>
		void setLayer(Layer layer);

		/// <summary>Check if GameObject's layer is one of the given layers</summary>
		bool inLayer(int layer);
		
		/// <summary>Check if those are the same layers</summary>
		bool isLayer(Layer layer);
#pragma endregion

#pragma region Rendering
		/// <summary>Sets sortingLayer</summary>
		void setSortingLayer(int sortingLayer);

		/// <summary>Returns actual SortingLayer</summary>
		int getSortingLayer();
#pragma endregion

#pragma region Component management
		/// <summary>Return's reference to container with all GameObject's components</summary>
		std::vector <Component*> &getComponents();

		/// <summary>Return's list of components that inherite from given class</summary>
		template <class T>
		std::vector <Component*> *getComponents();

		/// <summary>Return's first component in list of components that inherite from given class or NULL if no component found</summary>
		template <class T>
		T* getComponent();

		/// <summary>Adds new component to GameObject</summary>
		void addComponent(Component* component);
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

#pragma region Destroy 
		/// <summary>Destroys object before next tick</summary>
		void destroy(float nlifeTime = 0.0f);

		/// <summary>Checks if object is going to be destroyed</summary>
		bool shouldBeDestroyed();
#pragma endregion

	};

	template<class T>
	std::vector<Component*>* GameObject::getComponents()
	{
		std::vector <Component*> *chosen = new std::vector<Component*>();

		for each (Component* component in this->components)
		{
			if (dynamic_cast<T*>(component)) {
				chosen->push_back(component);
			}
		}

		return chosen;
	}

	template<class T>
	T* GameObject::getComponent()
	{
		T* getComp;
		for each (Component* component in components)
		{
			if (getComp = dynamic_cast<T*>(component)) {
				return getComp;
			}
		}
		return NULL;
	}
}

#endif // !_GAME_OBJECT_H_
