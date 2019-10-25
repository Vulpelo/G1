#pragma once

#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include "GameObject.h"

#include "GameObjectsData.h"
#include "Assets.h"

#include <vector>

#include <SFML\Graphics.hpp>

namespace G1 {

	class GameMap
	{
		//friend class PhysicsHandle;
		void insertGameObjectBySortingLayer(GameObject* gameObject);
	protected:
		std::vector <GameObject *> objects;
	public:
		GameMap();
		/// <summary> Return's a colection of Objects that where
		/// created in this GameMap </summary>
		std::vector <GameObject*> getAllObjects();
		void mainBeginPlay();
		void mainEventTick();
		virtual void eventTick(); //rdzen ustalany od postaci
	};

}

#endif // !_GAME_MAP_H_
