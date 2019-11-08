#pragma once

#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include "GameObject.h"

#include "GameObjectsData.h"
#include "Assets.h"

#include <vector>

#include <SFML\Graphics.hpp>

namespace G1 {

	class GameMap : public ITick
	{
		friend class MapManager;
		friend class Engine;

		void insertGameObjectBySortingLayer(GameObject* gameObject);

		void mainBeginPlay();
		void mainEventTick();

	protected:
		std::vector <GameObject *> objects;
	public:
		GameMap();
		/// <summary> Return's a colection of Objects that where
		/// created in this GameMap </summary>
		std::vector <GameObject*> getAllObjects();

		//void addGameObject(GameObject* gameObject);
		//void addGameObject(GameObject&& gameObject);

		/// <summary>
		/// Adds original gameObject to map
		/// </summary>
		/// <param name="gameObject"></param>
		void addGameObject(GameObject* gameObject) { objects.push_back(gameObject); }

		/// <summary>
		/// Adds copy of the GameObject to map
		/// </summary>
		template <class T>
		void addGameObject(T gameObject)
		{
			T* ngO = new T();
			*ngO = gameObject;
			objects.push_back(ngO);
		}
	};

}

#endif // !_GAME_MAP_H_
